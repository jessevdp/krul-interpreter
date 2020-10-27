#include "MapLabelRegistry.h"

namespace krul::interpreter {
  using namespace exception;

  void MapLabelRegistry::set(const label_name_t& label, label_t value) {
    _map[label] = value;
  }

  label_t MapLabelRegistry::get(const label_name_t& label) const {
    if (!is_defined(label)) throw UndefinedLabelException(label);
    return _map.at(label);
  }

  bool MapLabelRegistry::is_defined(const label_name_t& label) const {
    return _map.find(label) != _map.end();
  }

  std::unique_ptr<LabelRegistry> MapLabelRegistry::clone() const {
    return std::make_unique<MapLabelRegistry>(*this);
  }

}