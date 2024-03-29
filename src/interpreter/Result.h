#pragma once
#include "types.h"

namespace krul::interpreter {

  class Result {
  private:
    value_t _return_value;
    bool _is_end_of_search;

  public:
    Result(const value_t& return_value, bool is_end_of_search);
    [[nodiscard]] value_t return_value() const;
    [[nodiscard]] bool is_end_of_search() const;
  };

} // namespace krul::interpreter