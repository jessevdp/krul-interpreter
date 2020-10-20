#pragma once

#include "../Instruction.h"

namespace krul::interpreter::instructions {

  class Return : private Instruction {
  public:
    void execute(Context& context) const override;
  };

}
