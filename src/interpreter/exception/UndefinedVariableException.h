#pragma once

#include "InterpretingException.h"

#include <string>

namespace krul::interpreter::exception {

  class UndefinedVariableException : public InterpretingException {
  public:
    explicit UndefinedVariableException(const std::string& variable_name);
  };

} // namespace krul::interpreter::exception