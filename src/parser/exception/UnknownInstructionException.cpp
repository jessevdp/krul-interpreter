#include "UnknownInstructionException.h"

namespace krul::parser::exception {

  UnknownInstructionException::UnknownInstructionException(const std::string& instruction)
      : ParsingException("Unknown instruction '" + instruction + "'") {
  }

} // namespace krul::parser::exception