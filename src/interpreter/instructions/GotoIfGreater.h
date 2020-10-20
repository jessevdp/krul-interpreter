#pragma once

#include "../Instruction.h"

namespace krul::interpreter::instructions {

  class GotoIfGreater : public Instruction {
  public:
    void execute(Context& context) const override;
  };

}
