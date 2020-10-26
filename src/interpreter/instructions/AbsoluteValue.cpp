#include "AbsoluteValue.h"

#include <cmath>

namespace krul::interpreter::instructions {

  void AbsoluteValue::execute(Context& context) const {
    int number = context.stack().pop_as_int();
    int result = std::abs(number);
    value_t value = std::to_string(result);
    context.stack().push(value);
  }

  std::unique_ptr<Instruction> AbsoluteValue::clone() const {
    return std::make_unique<AbsoluteValue>(*this);
  }

} // namespace krul::interpreter::instructions