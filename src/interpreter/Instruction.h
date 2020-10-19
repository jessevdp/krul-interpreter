#pragma once

#include "Context.h"

namespace krul::interpreter {

  class Instruction {
  public:
    Instruction() = default;
    virtual ~Instruction() noexcept = default;

    virtual void execute(Context& context) const = 0;
  };

}