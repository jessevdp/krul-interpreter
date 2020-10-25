#include "TypeConversionException.h"

namespace krul::interpreter::exception {

  TypeConversionException::TypeConversionException(const std::string& value, const std::string& type_name)
      : std::logic_error("Failed to convert value: '" + value + "' to " + type_name) {
  }

} // namespace krul::interpreter::exception