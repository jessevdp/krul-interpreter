#include "Add.h"

namespace krul::interpreter::instructions {

  void Add::execute(Context& context) const {
    int a = context.stack().pop_as_int();
    int b = context.stack().pop_as_int();
    int result = a + b;
    value_t value = std::to_string(result);
    context.stack().push(value);
  }

} // namespace krul::interpreter::instructions