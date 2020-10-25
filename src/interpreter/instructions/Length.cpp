#include "Length.h"

namespace krul::interpreter::instructions {

  void Length::execute(Context& context) const {
    value_t value = context.stack().pop();
    int length = value.length();
    value_t result = std::to_string(length);
    context.stack().push(result);
  }

} // namespace krul::interpreter::instructions