#include "Decrement.h"

namespace krul::interpreter::instructions {

  void Decrement::execute(Context& context) const {
    int number = context.stack().pop_as_int();
    int result = number - 1;
    value_t value = std::to_string(result);
    context.stack().push(value);
  }

  std::unique_ptr<Instruction> Decrement::clone() const {
    return std::make_unique<Decrement>(*this);
  }

} // namespace krul::interpreter::instructions