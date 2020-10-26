#include "VariableReference.h"

namespace krul::interpreter::instructions {

  VariableReference::VariableReference(variable_t variable) : _variable {std::move(variable)} {
  }

  void VariableReference::execute(Context& context) const {
    value_t value = context.variables().get(_variable);
    context.stack().push(value);
  }

  std::unique_ptr<Instruction> VariableReference::clone() const {
    return std::make_unique<VariableReference>(*this);
  }

} // namespace krul::interpreter::instructions
