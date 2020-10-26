#include "ParsedProgram.h"

namespace krul::parser {

  ParsedProgram::ParsedProgram(std::vector<std::unique_ptr<interpreter::Instruction>>& instructions,
                               std::unique_ptr<interpreter::LabelRegistry>& label_registry)
      : _instructions {std::move(instructions)}, _label_registry {std::move(label_registry)} {
  }

  std::vector<std::unique_ptr<interpreter::Instruction>> ParsedProgram::instructions() const {
    std::vector<std::unique_ptr<interpreter::Instruction>> instructions;
    instructions.reserve(_instructions.size());

    for (auto& instruction : _instructions) {
      instructions.push_back(instruction->clone());
    }

    return instructions;
  }

  std::unique_ptr<interpreter::LabelRegistry> ParsedProgram::label_registry() const {
    return _label_registry->clone();
  }

} // namespace krul::parser