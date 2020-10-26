#pragma once

#include "interpreter/types.h"
#include "exception/UndefinedLabelException.h"

namespace krul::parser {

  class LabelRegistry {
  public:
    virtual void set(const std::string& label, interpreter::label_t value);

    /**
     * Get the value of a label
     * @throws UndefinedLabelException when the label has not been set
     * @param label name of the label to get
     */
    virtual void get(const std::string& label);
  };

}