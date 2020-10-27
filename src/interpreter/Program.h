#pragma once

#include "Result.h"

namespace krul::interpreter {

  class Program {
  public:
    virtual ~Program() noexcept = default;

    /**
     * Execute the instructions inside of the program.
     * @return result containing remaining value on the stack
     */
    virtual Result execute() = 0;
  };

} // namespace krul::interpreter