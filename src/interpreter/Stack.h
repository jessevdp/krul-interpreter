#pragma once

#include "exception/TypeConversionException.h"
#include "types.h"

#include <stdexcept>

namespace krul::interpreter {

  class Stack {
  public:
    virtual ~Stack() noexcept = default;

    virtual void push(value_t item) = 0;

    /**
     * @throws std::out_of_range if stack is empty
     * @return value at the top of the stack
     */
    virtual value_t pop() = 0;

    /**
     * @throws std::out_of_range if stack is empty
     * @return value at the top of the stack
     */
    [[nodiscard]] virtual value_t peek() const = 0;

    /**
     * Pop one value off the stack and convert it to int.
     * @throws exception::TypeConversionException
     * @return value converted to int
     */
    virtual int pop_as_int() = 0;

    /**
     * Peek at the value at the top of the Stack, converting it to int
     * @throws exception::TypeConversionException
     * @return value converted to int
     */
    [[nodiscard]] virtual int peek_as_int() const = 0;

    /**
     * Pop one value off the stack and convert it to label_t.
     * @throws exception::TypeConversionException
     * @return value converted to label_t
     */
    virtual label_t pop_as_label() = 0;

    /**
     * Peek at the value at the top of the Stack, converting it to label_t
     * @throws exception::TypeConversionException
     * @return value converted to label_t
     */
    [[nodiscard]] virtual label_t peek_as_label() const = 0;
  };

} // namespace krul::interpreter