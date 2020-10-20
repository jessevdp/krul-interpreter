#pragma once

#include "CallStack.h"
#include "Stack.h"
#include "VariableRegistry.h"
#include "types.h"

#include <stdexcept>

namespace krul::interpreter {

  class Context {
  public:
    virtual ~Context() noexcept = default;

    virtual Stack& stack() const = 0;
    virtual VariableRegistry& variables() const = 0;
    virtual CallStack& call_stack() const = 0;

    /**
     * Set the line # that determines which instruction is executed next.
     * @throws std::out_of_range
     * @param line
     */
    virtual void go_to_line(line_t line) = 0;
  };

} // namespace krul::interpreter