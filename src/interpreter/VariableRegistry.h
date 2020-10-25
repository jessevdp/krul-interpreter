#pragma once

#include "exception/UndefinedVariableException.h"
#include "types.h"

namespace krul::interpreter {

  class VariableRegistry {
  public:
    virtual ~VariableRegistry() noexcept = default;

    /**
     * Get the value of a variable by reference/name.
     * @throws exception::UndefinedVariableException when the variable has not been set
     * @param variable reference/name
     * @return
     */
    [[nodiscard]] virtual value_t get(const variable_t& variable) const = 0;

    /**
     * Set a variable (reference/name) to a value. Overwrites the previous value if it was there.
     * @param variable reference/name
     * @param value
     */
    virtual void set(const variable_t& variable, value_t value) = 0;
  };

} // namespace krul::interpreter