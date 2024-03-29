#include "GotoIfNotEqual.h"

namespace krul::interpreter::instructions {

  void GotoIfNotEqual::execute(Context& context) const {
    label_t label = context.stack().pop_as_label();
    value_t a = context.stack().pop();
    value_t b = context.stack().pop();

    if (a != b) { context.go_to_line(label); }
  }

  std::unique_ptr<Instruction> GotoIfNotEqual::clone() const {
    return std::make_unique<GotoIfNotEqual>(*this);
  }

} // namespace krul::interpreter::instructions