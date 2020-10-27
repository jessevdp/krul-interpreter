#pragma once

#include "interpreter/Context.h"
#include "interpreter/Instruction.h"
#include "interpreter/Program.h"

#include <memory>
#include <vector>

namespace krul {

  class KrulProgram : public interpreter::Program, public interpreter::Context {
  private:
    bool _found_end {false};
    interpreter::line_t _current_line {0};
    std::unique_ptr<interpreter::Stack> _stack;
    std::unique_ptr<interpreter::CallStack> _call_stack;
    std::unique_ptr<interpreter::VariableRegistry> _variables;
    std::unique_ptr<interpreter::LabelRegistry> _labels {nullptr};
    std::vector<std::unique_ptr<interpreter::Instruction>> _instructions;

    bool goto_executed {false};

  public:
    explicit KrulProgram(const std::string& source_code);
    interpreter::Result execute() override;

    //#region Context

    [[nodiscard]] interpreter::Stack& stack() const override;
    [[nodiscard]] interpreter::VariableRegistry& variables() const override;
    [[nodiscard]] interpreter::LabelRegistry& labels() const override;
    [[nodiscard]] interpreter::CallStack& call_stack() const override;

    [[nodiscard]] interpreter::line_t current_line() const override;
    void go_to_line(interpreter::line_t line) override;
    void found_end() override;

    //#endregion Context

  private:
    /**
     * Increment the line number unless a GOTO was just executed, in that case the line number is already set to the
     * correct next instruction.
     */
    void go_to_next_line();
  };

} // namespace krul
