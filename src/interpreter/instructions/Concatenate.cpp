#include "Concatenate.h"

namespace krul::interpreter::instructions {

  void Concatenate::execute(Context& context) const {
    value_t a = context.stack().pop();
    value_t b = context.stack().pop();
    value_t result = a + b;
    context.stack().push(result);
  }

  std::unique_ptr<Instruction> Concatenate::clone() const {
    return std::make_unique<Concatenate>(*this);
  }

} // namespace krul::interpreter::instructions