#include "VariableReference.h"

#include <utility>

namespace krul::interpreter::instructions {

  VariableReference::VariableReference(variable_t variable) : _variable {std::move(variable)} {
  }

  void VariableReference::execute(Context& context) const {
    value_t value = context.variables().get(_variable);
    context.stack().push(value);
  }

} // namespace krul::interpreter::instructions
