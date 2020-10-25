#pragma once

#include <exception>
#include <stdexcept>
#include <string>

namespace krul::interpreter::exception {

  class UndefinedVariableException : public std::logic_error {
  public:
    explicit UndefinedVariableException(const std::string& variable_name);
  };

} // namespace krul::interpreter::exception