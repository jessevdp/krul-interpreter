#include "Add.h"

namespace krul::interpreter::instructions {

  void Add::execute(Context& context) const {
    int a = context.stack().pop_as_int();
    int b = context.stack().pop_as_int();
    int result = a + b;
    value_t value = std::to_string(result);
    context.stack().push(value);
  }

  std::unique_ptr<Instruction> Add::clone() const {
    return std::make_unique<Add>(*this);
  }

} // namespace krul::interpreter::instructions