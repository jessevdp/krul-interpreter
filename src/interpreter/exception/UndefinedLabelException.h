#pragma once

#include "ParsingException.h"

namespace krul::interpreter::exception {

  class UndefinedLabelException : public ParsingException {
  public:
    explicit UndefinedLabelException(const std::string& label_name);
  };

}
