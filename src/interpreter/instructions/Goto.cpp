#include "Goto.h"

namespace krul::interpreter::instructions {

  void Goto::execute(Context& context) const {
    label_t label = context.stack().pop_as_label();
    context.go_to_line(label);
  }

  std::unique_ptr<Instruction> Goto::clone() const {
    return std::make_unique<Goto>(*this);
  }

} // namespace krul::interpreter::instructions