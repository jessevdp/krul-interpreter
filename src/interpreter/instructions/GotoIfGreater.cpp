#include "GotoIfGreater.h"

namespace krul::interpreter::instructions {

  void GotoIfGreater::execute(Context& context) const {
    label_t label = context.stack().pop_as_label();
    int b = context.stack().pop_as_int();
    int a = context.stack().pop_as_int();

    if (a > b) { context.go_to_line(label); }
  }

  std::unique_ptr<Instruction> GotoIfGreater::clone() const {
    return std::make_unique<GotoIfGreater>(*this);
  }

} // namespace krul::interpreter::instructions