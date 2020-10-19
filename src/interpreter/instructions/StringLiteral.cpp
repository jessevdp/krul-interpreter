#include "StringLiteral.h"

#include <utility>

namespace krul::interpreter::instructions {

  StringLiteral::StringLiteral(std::string value) : _value {std::move(value)} {
  }

  void StringLiteral::execute(Context& context) const {
    context.stack().push(_value);
  }

}
