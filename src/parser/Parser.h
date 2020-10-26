#pragma once

#include "ParsedProgram.h"

#include <vector>

namespace krul::parser {

  class Parser {
  public:
    virtual ~Parser() noexcept = default;
    std::unique_ptr<ParsedProgram> parse(const std::string& source_code);
  };

} // namespace krul::parser