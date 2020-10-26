#pragma once

#include <stdexcept>
#include <string>

namespace krul::interpreter::exception {

  class InterpretingException : public std::logic_error {
  protected:
    explicit InterpretingException(const std::string& message);
  };

} // namespace krul::interpreter::exception
