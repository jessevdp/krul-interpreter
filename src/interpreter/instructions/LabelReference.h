#pragma once

#include "../Instruction.h"

namespace krul::interpreter::instructions {

  class LabelReference : public Instruction {
  private:
    label_name_t _label;

  public:
    explicit LabelReference(label_name_t label);
    void execute(Context& context) const override;
    [[nodiscard]] std::unique_ptr<Instruction> clone() const override;
  };

} // namespace krul::interpreter::instructions
