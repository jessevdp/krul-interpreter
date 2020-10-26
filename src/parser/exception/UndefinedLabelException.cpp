#include "UndefinedLabelException.h"

namespace krul::parser::exception {

  UndefinedLabelException::UndefinedLabelException(const std::string& label_name)
      : InterpretingException("Label '" + label_name + "' is not defined") {
  }

} // namespace krul::parser::exception
