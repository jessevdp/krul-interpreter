#include "Index.h"

namespace krul::interpreter::instructions {

  void Index::execute(Context& context) const {
    int index = context.stack().pop_as_int();
    value_t value = context.stack().pop();
    value_t character = value.substr(index, 1);
    context.stack().push(character);
  }

} // namespace krul::interpreter::instructions