#include "Increment.h"

namespace krul::interpreter::instructions {

  void Increment::execute(Context& context) const {
    int number = context.stack().pop_as_int();
    int result = number + 1;
    value_t value = std::to_string(result);
    context.stack().push(value);
  }

  std::unique_ptr<Instruction> Increment::clone() const {
    return std::make_unique<Increment>(*this);
  }

} // namespace krul::interpreter::instructions