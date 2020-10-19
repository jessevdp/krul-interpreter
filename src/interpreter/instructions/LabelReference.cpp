#include "LabelReference.h"

namespace krul::interpreter::instructions {

  LabelReference::LabelReference(label_t label) : _label {label} {
  }

  void LabelReference::execute(Context& context) const {
    value_t value = std::to_string(_label);
    context.stack().push(value);
  }
}
