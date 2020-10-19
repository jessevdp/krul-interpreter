#pragma once

#include "../Instruction.h"

namespace krul::interpreter::instructions {

  class VariableAssignment : public Instruction {
  private:
    variable_t _variable;

  public:
    explicit VariableAssignment(variable_t variable);
    void execute(Context& context) const override;
  };

} // namespace krul::interpreter::instructions
