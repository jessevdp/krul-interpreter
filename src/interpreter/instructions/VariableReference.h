#pragma once

#include "../Instruction.h"

namespace krul::interpreter::instructions {

  class VariableReference : public Instruction {
  private:
    variable_t _variable;
  public:
    explicit VariableReference(variable_t variable);
    void execute(Context& context) const override;
  };

}
