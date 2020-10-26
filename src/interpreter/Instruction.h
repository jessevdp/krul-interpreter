#pragma once

#include "Context.h"

#include <memory>

namespace krul::interpreter {

  class Instruction {
  public:
    virtual ~Instruction() noexcept = default;
    virtual void execute(Context& context) const = 0;
    virtual std::unique_ptr<Instruction> clone() const = 0;
  };

} // namespace krul::interpreter