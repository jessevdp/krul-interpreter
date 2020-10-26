#include "Function.h"

namespace krul::interpreter::instructions {

  void Function::execute(Context& context) const {
    line_t return_line = context.current_line() + 1;
    context.call_stack().push(return_line);
    Goto::execute(context);
  }

  std::unique_ptr<Instruction> Function::clone() const {
    return std::make_unique<Function>(*this);
  }

} // namespace krul::interpreter::instructions