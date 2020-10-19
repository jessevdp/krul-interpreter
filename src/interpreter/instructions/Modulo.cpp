#include "Modulo.h"

namespace krul::interpreter::instructions {

  void Modulo::execute(Context& context) const {
    int a = context.stack().pop_as_int();
    int b = context.stack().pop_as_int();
    int result = b % a;
    value_t value = std::to_string(result);
    context.stack().push(value);
  }

}