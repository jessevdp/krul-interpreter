#include "ParsingException.h"

namespace krul::parser::exception {

  ParsingException::ParsingException(const std::string& message) : std::logic_error(message) {
  }

}