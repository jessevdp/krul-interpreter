#pragma once

#include <exception>
#include <stdexcept>
#include <string>

namespace krul::interpreter::exception {

  class TypeConversionException : public std::logic_error {
  public:
    TypeConversionException(const std::string& value, const std::string& type_name);
  };

} // namespace krul::interpreter::exception
