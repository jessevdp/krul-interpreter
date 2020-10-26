#include "GotoIfGreaterOrEqual.h"

namespace krul::interpreter::instructions {

  void GotoIfGreaterOrEqual::execute(Context& context) const {
    label_t label = context.stack().pop_as_label();
    int a = context.stack().pop_as_int();
    int b = context.stack().pop_as_int();

    if (a >= b) { context.go_to_line(label); }
  }

  std::unique_ptr<Instruction> GotoIfGreaterOrEqual::clone() const {
    return std::make_unique<GotoIfGreaterOrEqual>(*this);
  }

} // namespace krul::interpreter::instructions