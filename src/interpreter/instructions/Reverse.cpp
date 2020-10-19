#include "Reverse.h"

namespace krul::interpreter::instructions {

  void Reverse::execute(Context& context) const {
    value_t value = context.stack().pop();
    std::reverse(value.begin(), value.end());
    context.stack().push(value);
  }

}