#pragma once

#include "ParsedProgram.h"

#include <memory>
#include <string>

namespace krul::parser {

  class Parser {
  public:
    virtual ~Parser() noexcept = default;
    virtual std::unique_ptr<ParsedProgram> parse(const std::string& source_code) const = 0;
  };

} // namespace krul::parser