#include "Newline.h"

namespace krul::interpreter::instructions {

  void Newline::execute(Context& context) const {
    value_t value = context.stack().pop();
    value += '\n';
    context.stack().push(value);
  }

  std::unique_ptr<Instruction> Newline::clone() const {
    return std::make_unique<Newline>(*this);
  }

} // namespace krul::interpreter::instructions