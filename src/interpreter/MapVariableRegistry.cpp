#include "MapVariableRegistry.h"

namespace krul::interpreter {
  using namespace exception;

  void MapVariableRegistry::set(const variable_t& variable, value_t value) {
    _map[variable] = value;
  }

  value_t MapVariableRegistry::get(const variable_t& variable) const {
    if (!is_defined(variable)) throw UndefinedVariableException(variable);
    return _map.at(variable);
  }

  bool MapVariableRegistry::is_defined(const variable_t& variable) const {
    return _map.find(variable) != _map.end();
  }

}
