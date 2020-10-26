#pragma once

#include "interpreter/Instruction.h"
#include "interpreter/LabelRegistry.h"

#include <memory>
#include <vector>

namespace krul::parser {

  class ParsedProgram {
  private:
    std::vector<std::unique_ptr<interpreter::Instruction>> _instructions;
    std::unique_ptr<interpreter::LabelRegistry> _label_registry;

  public:
    ParsedProgram(std::vector<std::unique_ptr<interpreter::Instruction>>& _instructions, std::unique_ptr<interpreter::LabelRegistry>& _label_registry);

    [[nodiscard]] std::unique_ptr<interpreter::LabelRegistry> label_registry() const;
    [[nodiscard]] std::vector<std::unique_ptr<interpreter::Instruction>> instructions() const;
  };

}


