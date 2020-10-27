#pragma once

#include "InterpretingException.h"

#include <string>

namespace krul::interpreter::exception {

  class UndefinedLabelException : public InterpretingException {
  public:
    explicit UndefinedLabelException(const std::string& label_name);
  };

}
