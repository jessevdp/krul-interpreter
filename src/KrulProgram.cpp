#include "KrulProgram.h"

#include "interpreter/MapVariableRegistry.h"
#include "interpreter/VectorCallStack.h"
#include "interpreter/VectorStack.h"
#include "parser/DefaultParser.h"
#include "parser/Parser.h"

namespace krul {
  using namespace parser;
  using namespace interpreter;

  interpreter::Result KrulProgram::execute() {
    while (_current_line < _instructions.size() && !_found_end) {
      const auto& instruction = _instructions.at(_current_line);
      instruction->execute(*this);
      go_to_next_line();
    }

    return Result(_stack->peek(), _found_end);
  }

  KrulProgram::KrulProgram(const std::string& source_code)
      : _stack {std::make_unique<VectorStack>()}, _call_stack {std::make_unique<VectorCallStack>()},
        _variables {std::make_unique<MapVariableRegistry>()} {
    std::unique_ptr<Parser> parser = std::make_unique<DefaultParser>();
    auto parsed_program = parser->parse(source_code);
    _instructions = parsed_program->instructions();
    _labels = parsed_program->label_registry();
  }

  interpreter::Stack& KrulProgram::stack() const {
    return *_stack;
  }

  interpreter::VariableRegistry& KrulProgram::variables() const {
    return *_variables;
  }

  interpreter::LabelRegistry& KrulProgram::labels() const {
    return *_labels;
  }

  interpreter::CallStack& KrulProgram::call_stack() const {
    return *_call_stack;
  }

  interpreter::line_t KrulProgram::current_line() const {
    return _current_line;
  }

  void KrulProgram::found_end() {
    _found_end = true;
  }

  void KrulProgram::go_to_line(interpreter::line_t line) {
    goto_executed = true;
    _current_line = line;
  }

  void KrulProgram::go_to_next_line() {
    if (goto_executed) goto_executed = false;
    else _current_line++;
  }

} // namespace krul