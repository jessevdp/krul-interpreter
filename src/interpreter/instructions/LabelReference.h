#pragma once

#include "../Instruction.h"

namespace krul::interpreter::instructions {

  class LabelReference : public Instruction {
  private:
    label_t _label;

  public:
    explicit LabelReference(label_t label);
    void execute(Context& context) const override;
  };

} // namespace krul::interpreter::instructions
