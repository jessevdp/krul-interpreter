#include "Length.h"

namespace krul::interpreter::instructions {

  void Length::execute(Context& context) const {
    value_t value = context.stack().pop();
    int length = value.length();
    value_t result = std::to_string(length);
    context.stack().push(result);
  }

  std::unique_ptr<Instruction> Length::clone() const {
    return std::make_unique<Length>(*this);
  }

} // namespace krul::interpreter::instructions