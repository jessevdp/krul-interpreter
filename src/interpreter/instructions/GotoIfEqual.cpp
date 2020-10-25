#include "GotoIfEqual.h"

namespace krul::interpreter::instructions {

  void GotoIfEqual::execute(Context& context) const {
    label_t label = context.stack().pop_as_label();
    value_t a = context.stack().pop();
    value_t b = context.stack().pop();

    if (a == b) { context.go_to_line(label); }
  }

} // namespace krul::interpreter::instructions