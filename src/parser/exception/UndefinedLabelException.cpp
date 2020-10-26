#include "UndefinedLabelException.h"

namespace krul::parser::exception {

  UndefinedLabelException::UndefinedLabelException(const std::string& label_name)
      : ParsingException("Label '" + label_name + "' is not defined") {
  }

} // namespace krul::parser::exception
