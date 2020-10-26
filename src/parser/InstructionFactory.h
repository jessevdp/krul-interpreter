#pragma once

#include "interpreter/Instruction.h"
#include "exception/UnknownInstructionException.h"

#include <functional>
#include <memory>
#include <string>

namespace krul::parser {

  using InstructionSupplier = std::function<std::unique_ptr<interpreter::Instruction>(const std::string& arguments)>;

  class InstructionFactory {
  public:
    virtual ~InstructionFactory() noexcept = default;

    virtual void register_supplier(const std::string& instruction, InstructionSupplier supplier) = 0;

    /**
     * Create an instruction based on its string representation
     * @param instruction string representation
     * @param arguments extra arguments passed to the InstructionSupplier
     * @throws UnknownInstructionException
     * @return
     */
    [[nodiscard]] virtual std::unique_ptr<interpreter::Instruction> create(const std::string& instruction,
                                                                           const std::string& arguments) const = 0;
  };

} // namespace krul::parser