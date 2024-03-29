#pragma once

#include "../Instruction.h"
#include "Goto.h"

namespace krul::interpreter::instructions {

  class Function : public Goto {
  public:
    void execute(Context& context) const override;
    [[nodiscard]] std::unique_ptr<Instruction> clone() const override;
  };

} // namespace krul::interpreter::instructions
