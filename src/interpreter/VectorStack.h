#pragma once

#include "Stack.h"

#include <vector>

namespace krul::interpreter {

  class VectorStack : public Stack {
  private:
    std::vector<value_t> _vector;

  public:
    void push(value_t item) override;
    value_t pop() override;
    [[nodiscard]] value_t peek() const override;

    int pop_as_int() override;
    [[nodiscard]] int peek_as_int() const override;

    label_t pop_as_label() override;
    [[nodiscard]] label_t peek_as_label() const override;

  private:
    void throw_if_empty() const;
    static int convert_to_int(const value_t& item);
    static label_t convert_to_label(const value_t& item);
  };

}
