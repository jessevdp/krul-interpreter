#pragma once

#include "Parser.h"
#include "InstructionFactory.h"

#include <memory>
#include <vector>
#include <string>

namespace krul::parser {

  class DefaultParser : public Parser {
  private:
    std::unique_ptr<InstructionFactory> _instruction_factory;

    class InstructionDefinition {
    public:
      std::string instruction;
      std::string arguments;

    public:
      explicit InstructionDefinition(std::string name, std::string args = "");
    };

  public:
    DefaultParser();
    explicit DefaultParser(std::unique_ptr<InstructionFactory>& instruction_factory);
    [[nodiscard]] std::unique_ptr<ParsedProgram> parse(const std::string& source_code) const override;

  private:
    static std::vector<std::string> split_lines(const std::string& string);
    static std::vector<std::string> filter_and_register_labels(const std::vector<std::string>& lines, interpreter::LabelRegistry& label_registry);
    static std::vector<InstructionDefinition> convert_to_definitions(const std::vector<std::string>& lines);
  };

}


