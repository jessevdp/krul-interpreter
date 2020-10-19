#include "Duplicate.h"

namespace krul::interpreter::instructions {

  void Duplicate::execute(Context& context) const {
    value_t value = context.stack().peek();
    context.stack().push(value);
  }

}