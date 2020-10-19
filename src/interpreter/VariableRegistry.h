#pragma once

#include "types.h"

#include <stdexcept>

namespace krul::interpreter {

  class VariableRegistry {
  public:
    virtual ~VariableRegistry() noexcept = default;

    /**
     * Get the value of a variable by reference/name.
     * @throws std::out_of_range when the variable has not been set
     * @param variable reference/name
     * @return
     */
    virtual value_t get(variable_t variable) const = 0;

    /**
     * Set a variable (reference/name) to a value. Overwrites the previous value if it was there.
     * @param variable reference/name
     * @param value
     */
    virtual void set(variable_t variable, value_t value) = 0;
  };

}