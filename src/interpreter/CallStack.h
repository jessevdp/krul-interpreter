#pragma once

#include "types.h"

namespace krul::interpreter {

  class CallStack {
  public:
    virtual ~CallStack() noexcept = default;

    virtual void push(line_t line) = 0;
    virtual line_t pop() = 0;
  };

} // namespace krul::interpreter