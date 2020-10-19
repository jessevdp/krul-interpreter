#include "Increment.h"

namespace krul::interpreter::instructions {

  void Increment::execute(Context& context) const {
    int number = context.stack().pop_as_int();
    int result = number + 1;
    value_t value = std::to_string(result);
    context.stack().push(value);
  }

}