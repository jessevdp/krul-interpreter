#include "StringLiteral.h"

#include <utility>

namespace krul::interpreter::instructions {

  StringLiteral::StringLiteral(std::string value) : _value {std::move(value)} {
  }

  void StringLiteral::execute(Context& context) const {
    context.stack().push(_value);
  }

  std::unique_ptr<Instruction> StringLiteral::clone() const {
    return std::make_unique<StringLiteral>(*this);
  }

} // namespace krul::interpreter::instructions
