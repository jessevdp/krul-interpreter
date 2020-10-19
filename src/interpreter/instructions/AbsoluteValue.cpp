#include "AbsoluteValue.h"

#include <cmath>

namespace krul::interpreter::instructions {

  void AbsoluteValue::execute(Context& context) const {
    int number = context.stack().pop_as_int();
    int result = std::abs(number);
    value_t value = std::to_string(result);
    context.stack().push(value);
  }

} // namespace krul::interpreter::instructions