#include "LabelReference.h"

namespace krul::interpreter::instructions {

  LabelReference::LabelReference(label_name_t label) : _label {label} {
  }

  void LabelReference::execute(Context& context) const {
    label_t label = context.labels().get(_label);
    value_t value = std::to_string(label);
    context.stack().push(value);
  }

  std::unique_ptr<Instruction> LabelReference::clone() const {
    return std::make_unique<LabelReference>(*this);
  }

} // namespace krul::interpreter::instructions
