#pragma once

#include <stdexcept>
#include <string>

namespace krul::parser::exception {

  class ParsingException : public std::logic_error {
  public:
    explicit ParsingException(const std::string& message);
  };

}


