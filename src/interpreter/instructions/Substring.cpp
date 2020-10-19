#include "Substring.h"

namespace krul::interpreter::instructions {

  void Substring::execute(Context& context) const {
    int to = context.stack().pop_as_int();
    int from = context.stack().pop_as_int();
    int length = to - from;
    value_t value = context.stack().pop();
    value_t substring = value.substr(from, length);
    context.stack().push(substring);
  }

} // namespace krul::interpreter::instructions