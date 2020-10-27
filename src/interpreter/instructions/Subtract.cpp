#include "Subtract.h"

namespace krul::interpreter::instructions {

  void Subtract::execute(Context& context) const {
    int a = context.stack().pop_as_int();
    int b = context.stack().pop_as_int();
    int result = b - a;
    value_t value = std::to_string(result);
    context.stack().push(value);
  }

  std::unique_ptr<Instruction> Subtract::clone() const {
    return std::make_unique<Subtract>(*this);
  }

} // namespace krul::interpreter::instructions