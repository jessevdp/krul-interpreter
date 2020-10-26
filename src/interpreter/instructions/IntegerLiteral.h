#pragma once

#include "../Instruction.h"

namespace krul::interpreter::instructions {

  class IntegerLiteral : public Instruction {
  private:
    unsigned int _value;

  public:
    explicit IntegerLiteral(unsigned int value);
    void execute(Context& context) const override;
    [[nodiscard]] std::unique_ptr<Instruction> clone() const override;
  };

} // namespace krul::interpreter::instructions
