#pragma once

#include "CallStack.h"

#include <vector>

namespace krul::interpreter {

  class VectorCallStack : public CallStack {
  private:
    std::vector<line_t> _vector;

  public:
    void push(line_t line) override;
    line_t pop() override;
  };

} // namespace krul::interpreter
