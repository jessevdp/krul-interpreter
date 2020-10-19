#include "Multiply.h"

namespace krul::interpreter::instructions {

  void Multiply::execute(Context& context) const {
    int a = context.stack().pop_as_int();
    int b = context.stack().pop_as_int();
    int result = a * b;
    value_t value = std::to_string(result);
    context.stack().push(value);
  }

}