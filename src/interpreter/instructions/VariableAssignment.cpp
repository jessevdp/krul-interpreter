#include "VariableAssignment.h"

#include <utility>

namespace krul::interpreter::instructions {

  VariableAssignment::VariableAssignment(variable_t variable) : _variable {std::move(variable)} {
  }

  void VariableAssignment::execute(Context& context) const {
    value_t value = context.stack().pop();
    context.variables().set(_variable, value);
  }

  std::unique_ptr<Instruction> VariableAssignment::clone() const {
    return std::make_unique<VariableAssignment>(*this);
  }

} // namespace krul::interpreter::instructions
