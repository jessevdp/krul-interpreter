#include "InterpretingException.h"

namespace krul::interpreter::exception {

  InterpretingException::InterpretingException(const std::string& message) : std::logic_error(message) {
  }

} // namespace krul::interpreter::exception