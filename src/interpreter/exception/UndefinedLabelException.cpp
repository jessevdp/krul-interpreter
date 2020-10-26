#include "UndefinedLabelException.h"

namespace krul::interpreter::exception {

  UndefinedLabelException::UndefinedLabelException(const std::string& label_name)
      : InterpretingException("Label '" + label_name + "' is not defined") {
  }

} // namespace krul::parser::exception
