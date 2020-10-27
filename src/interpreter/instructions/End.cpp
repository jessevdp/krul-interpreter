#include "End.h"

namespace krul::interpreter::instructions {

  void End::execute(Context& context) const {
    context.found_end();
  }

  std::unique_ptr<Instruction> End::clone() const {
    return std::make_unique<End>(*this);
  }

} // namespace krul::interpreter::instructions