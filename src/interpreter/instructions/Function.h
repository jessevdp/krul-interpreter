#pragma once

#include "../Instruction.h"
#include "Goto.h"

namespace krul::interpreter::instructions {

  class Function : private Goto {
  public:
    void execute(Context& context) const override;
  };

}
