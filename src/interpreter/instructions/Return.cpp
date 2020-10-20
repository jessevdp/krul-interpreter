#include "Return.h"

namespace krul::interpreter::instructions {

  void Return::execute(Context& context) const {
    line_t return_line = context.call_stack().pop();
    context.go_to_line(return_line);
  }

}