#pragma once

#include "InterpretingException.h"

namespace krul::parser::exception {

  class UndefinedLabelException : public InterpretingException {
  public:
    UndefinedLabelException(const std::string& label_name);
  };

}
