#include "Index.h"

namespace krul::interpreter::instructions {

  void Index::execute(Context& context) const {
    int index = context.stack().pop_as_int();
    value_t value = context.stack().pop();
    value_t character = value.substr(index, 1);
    context.stack().push(character);
  }

  std::unique_ptr<Instruction> Index::clone() const {
    return std::make_unique<Index>(*this);
  }

} // namespace krul::interpreter::instructions