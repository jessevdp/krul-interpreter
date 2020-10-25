#pragma once

#include "VariableRegistry.h"

#include <map>

namespace krul::interpreter {

  class MapVariableRegistry : public VariableRegistry {
  private:
    std::map<variable_t, value_t> _map;

  public:
    [[nodiscard]] value_t get(const variable_t& variable) const override;
    void set(const variable_t& variable, value_t value) override;

  private:
    [[nodiscard]] bool is_defined(const variable_t& variable) const;
  };

}


