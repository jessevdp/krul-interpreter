#pragma once

#include "../Instruction.h"

namespace krul::interpreter::instructions {

  class StringLiteral : public Instruction {
  private:
    std::string _value;

  public:
    explicit StringLiteral(std::string value);
    void execute(Context& context) const override;
    [[nodiscard]] std::unique_ptr<Instruction> clone() const override;
  };

} // namespace krul::interpreter::instructions
