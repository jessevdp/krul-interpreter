#pragma once

#include "exception/UndefinedLabelException.h"
#include "types.h"

namespace krul::interpreter {

  class LabelRegistry {
  public:
    virtual ~LabelRegistry() noexcept = default;

    virtual void set(const label_name_t& label, label_t value) = 0;

    /**
     * Get the value of a label
     * @throws UndefinedLabelException when the label has not been set
     * @param label name of the label to get
     */
    virtual label_t get(const label_name_t& label) = 0;
  };

}