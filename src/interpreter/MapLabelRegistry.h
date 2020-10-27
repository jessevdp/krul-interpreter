#pragma once

#include "LabelRegistry.h"

#include <map>
#include <memory>

namespace krul::interpreter {

  class MapLabelRegistry : public LabelRegistry {
  private:
    std::map<label_name_t, label_t> _map;

  public:
    label_t get(const label_name_t& label) const override;
    void set(const label_name_t& label, label_t value) override;
    [[nodiscard]] std::unique_ptr<LabelRegistry> clone() const override;

  private:
    bool is_defined(const label_name_t& label) const;
  };

} // namespace krul::interpreter
