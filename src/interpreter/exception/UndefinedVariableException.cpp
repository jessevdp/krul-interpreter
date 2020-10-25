#include "UndefinedVariableException.h"

namespace krul::interpreter::exception {

  UndefinedVariableException::UndefinedVariableException(const std::string& variable_name)
      : std::logic_error("Variable '" + variable_name + "' is not defined") {
  }

} // namespace krul::interpreter::exception