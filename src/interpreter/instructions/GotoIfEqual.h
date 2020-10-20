#pragma once

#include "../Instruction.h"

namespace krul::interpreter::instructions {

  class GotoIfEqual : public Instruction {
  public:
    void execute(Context& context) const override;
  };

}
