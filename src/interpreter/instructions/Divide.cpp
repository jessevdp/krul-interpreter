#include "Divide.h"

namespace krul::interpreter::instructions {

  void Divide::execute(Context& context) const {
    int a = context.stack().pop_as_int();
    int b = context.stack().pop_as_int();
    int result = b / a;
    value_t value = std::to_string(result);
    context.stack().push(value);
  }

} // namespace krul::interpreter::instructions