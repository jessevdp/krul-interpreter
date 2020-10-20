#pragma once

#include "types.h"

namespace krul::interpreter {

  class Stack {
  public:
    virtual ~Stack() noexcept = default;

    virtual void push(value_t item) = 0;
    virtual value_t pop() = 0;
    virtual value_t peek() const = 0;

    virtual int pop_as_int() = 0;
    virtual int peek_as_int() const = 0;
  };

} // namespace krul::interpreter