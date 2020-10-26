#pragma once

#include "InstructionFactory.h"

#include <map>

namespace krul::parser {

  /**
   * InstructionFactory implementation that registers its own default suppliers.
   */
  class DefaultInstructionFactory : public InstructionFactory {
  private:
    std::map<std::string, InstructionSupplier> _suppliers;

  public:
    DefaultInstructionFactory();

    void register_supplier(const std::string& instruction, InstructionSupplier supplier) override;
    [[nodiscard]] std::unique_ptr<interpreter::Instruction> create(const std::string& instruction,
                                                                   const std::string& arguments) const override;

  private:
    void register_default_suppliers();
    [[nodiscard]] bool has_supplier(const std::string& instruction) const;
  };

} // namespace krul::parser
