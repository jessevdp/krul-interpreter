#include "DefaultParser.h"

#include "DefaultInstructionFactory.h"
#include "interpreter/LabelRegistry.h"
#include "interpreter/MapLabelRegistry.h"

#include <regex>
#include <sstream>
#include <utility>

namespace krul::parser {
  using namespace interpreter;

  DefaultParser::DefaultParser() : _instruction_factory {std::make_unique<DefaultInstructionFactory>()} {
  }

  DefaultParser::DefaultParser(std::unique_ptr<InstructionFactory>& instruction_factory)
      : _instruction_factory {std::move(instruction_factory)} {
  }

  std::unique_ptr<ParsedProgram> DefaultParser::parse(const std::string& source_code) const {
    std::unique_ptr<LabelRegistry> label_registry = std::make_unique<MapLabelRegistry>();

    std::vector<std::string> lines = split_lines(source_code);
    std::vector<std::string> lines_with_instructions = filter_and_register_labels(lines, *label_registry);
    std::vector<InstructionDefinition> instruction_definitions = convert_to_definitions(lines_with_instructions);

    std::vector<std::unique_ptr<Instruction>> instructions;
    instructions.reserve(instruction_definitions.size());

    for (const auto& definition : instruction_definitions) {
      std::unique_ptr<Instruction> instruction =
        _instruction_factory->create(definition.instruction, definition.arguments);
      instructions.push_back(std::move(instruction));
    }

    return std::make_unique<ParsedProgram>(instructions, label_registry);
  }

  std::vector<std::string> DefaultParser::split_lines(const std::string& string) {
    std::stringstream sstream {string};
    std::vector<std::string> lines;
    std::string segment;
    char linebreak {'\n'};

    while (std::getline(sstream, segment, linebreak)) {
      lines.push_back(segment);
    }

    return lines;
  }

  std::vector<std::string> DefaultParser::filter_and_register_labels(const std::vector<std::string>& lines,
                                                                     interpreter::LabelRegistry& label_registry) {
    std::vector<std::string> lines_with_instructions;

    for (auto line : lines) {
      if (line.at(0) == ':') {
        label_name_t label_name = line.substr(1, line.size() - 1);
        label_t line_nr = lines_with_instructions.size();
        label_registry.set(label_name, line_nr);
      } else {
        lines_with_instructions.push_back(line);
      }
    }

    return lines_with_instructions;
  }

  std::vector<DefaultParser::InstructionDefinition>
  DefaultParser::convert_to_definitions(const std::vector<std::string>& lines) {
    std::vector<InstructionDefinition> instruction_definitions;
    instruction_definitions.reserve(lines.size());

    for (const auto& line : lines) {
      InstructionDefinition definition {line};

      if (std::regex_match(line, std::regex {"^\\d+$"})) {
        definition = InstructionDefinition {"integer-literal", line};
      } else if (std::regex_match(line, std::regex {"^[\\\\>=$].+"})) {
        std::string instruction = line.substr(0, 1);
        std::string arguments = line.substr(1, line.size() - 1);
        definition = InstructionDefinition {instruction, arguments};
      }

      instruction_definitions.push_back(definition);
    }

    return instruction_definitions;
  }

  DefaultParser::InstructionDefinition::InstructionDefinition(std::string name, std::string args)
      : instruction {std::move(name)}, arguments {std::move(args)} {};

} // namespace krul::parser