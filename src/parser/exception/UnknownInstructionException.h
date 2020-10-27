#pragma once

#include "ParsingException.h"

namespace krul::parser::exception {

  class UnknownInstructionException : public ParsingException {
  public:
    explicit UnknownInstructionException(const std::string& instruction);
  };

} // namespace krul::parser::exception
