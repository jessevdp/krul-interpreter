#include "IntegerLiteral.h"

namespace krul::interpreter::instructions {

  IntegerLiteral::IntegerLiteral(unsigned int value) : _value {value} {
  }

  void IntegerLiteral::execute(Context& context) const {
    value_t value = std::to_string(_value);
    context.stack().push(value);
  }

  std::unique_ptr<Instruction> IntegerLiteral::clone() const {
    return std::make_unique<IntegerLiteral>(*this);
  }

} // namespace krul::interpreter::instructions
