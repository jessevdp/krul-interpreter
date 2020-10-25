#pragma once

#include "types.h"

#include <stdexcept>

namespace krul::interpreter {

  class CallStack {
  public:
    virtual ~CallStack() noexcept = default;

    virtual void push(line_t line) = 0;

    /**
     * @throws std::out_of_range if stack is empty
     * @return value at the top of the stack
     */
    virtual line_t pop() = 0;
  };

} // namespace krul::interpreter