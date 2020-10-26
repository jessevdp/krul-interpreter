#pragma once

#include "InterpretingException.h"

#include <string>

namespace krul::interpreter::exception {

  class TypeConversionException : public InterpretingException {
  public:
    TypeConversionException(const std::string& value, const std::string& type_name);
  };

} // namespace krul::interpreter::exception
