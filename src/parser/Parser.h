#pragma once

#include "interpreter/Program.h"

#include <vector>

namespace krul::parser {

  class Parser {
  public:
    virtual ~Parser() noexcept = default;
    std::unique_ptr<interpreter::Program> parse(const std::string& source_code);
  };

} // namespace krul::parser