#include "Result.h"

namespace krul::interpreter {

  Result::Result(const value_t& return_value, bool is_end_of_search)
      : _return_value {return_value}, _is_end_of_search {is_end_of_search} {
  }

  value_t Result::return_value() const {
    return _return_value;
  }

  bool Result::is_end_of_search() const {
    return _is_end_of_search;
  }

} // namespace krul::interpreter