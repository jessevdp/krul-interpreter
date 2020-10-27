#pragma once

#include "../Instruction.h"

namespace krul::interpreter::instructions {

  class End : public Instruction {
  public:
    void execute(Context& context) const override;
    [[nodiscard]] std::unique_ptr<Instruction> clone() const override;
  };

}