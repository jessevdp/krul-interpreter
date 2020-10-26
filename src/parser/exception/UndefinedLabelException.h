#pragma once

#include "ParsingException.h"

namespace krul::parser::exception {

  class UndefinedLabelException : public ParsingException {
  public:
    UndefinedLabelException(const std::string& label_name);
  };

}
