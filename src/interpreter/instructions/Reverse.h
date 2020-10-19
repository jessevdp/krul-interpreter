#pragma once

#include "../Instruction.h"

namespace krul::interpreter::instructions {

  class Reverse : public Instruction {
  public:
    void execute(Context& context) const override;
  };

} // namespace krul::interpreter::instructions
