#include "DefaultInstructionFactory.h"

// Values & Types
#include "interpreter/instructions/IntegerLiteral.h"
#include "interpreter/instructions/LabelReference.h"
#include "interpreter/instructions/StringLiteral.h"
#include "interpreter/instructions/VariableAssignment.h"
#include "interpreter/instructions/VariableReference.h"

// Integer operations
#include "interpreter/instructions/AbsoluteValue.h"
#include "interpreter/instructions/Add.h"
#include "interpreter/instructions/Decrement.h"
#include "interpreter/instructions/Divide.h"
#include "interpreter/instructions/Increment.h"
#include "interpreter/instructions/Modulo.h"
#include "interpreter/instructions/Multiply.h"
#include "interpreter/instructions/Negate.h"
#include "interpreter/instructions/Subtract.h"

// String operations
#include "interpreter/instructions/Concatenate.h"
#include "interpreter/instructions/Duplicate.h"
#include "interpreter/instructions/Index.h"
#include "interpreter/instructions/Length.h"
#include "interpreter/instructions/Newline.h"
#include "interpreter/instructions/Reverse.h"
#include "interpreter/instructions/Rot13.h"
#include "interpreter/instructions/Substring.h"

// Tests & jumps
#include "interpreter/instructions/Goto.h"
#include "interpreter/instructions/GotoIfEqual.h"
#include "interpreter/instructions/GotoIfGreater.h"
#include "interpreter/instructions/GotoIfGreaterOrEqual.h"
#include "interpreter/instructions/GotoIfLess.h"
#include "interpreter/instructions/GotoIfLessOrEqual.h"
#include "interpreter/instructions/GotoIfNotEqual.h"

// Functions
#include "interpreter/instructions/Function.h"
#include "interpreter/instructions/Return.h"

// End of search
#include "interpreter/instructions/End.h"

// Standard library
#include <exception>
#include <memory>

namespace krul::parser {
  using namespace exception;
  using namespace interpreter;

  static int convert_to_int(const std::string& string) {
    try {
      return std::stoi(string);
    } catch (const std::exception& e) { throw ParsingException {"Can not convert '" + string + "' to integer"}; }
  }

  DefaultInstructionFactory::DefaultInstructionFactory() {
    register_default_suppliers();
  }

  void DefaultInstructionFactory::register_default_suppliers() {
    //#region Values & types

    register_supplier(
      "integer-literal", [](const std::string& arguments) -> auto {
        unsigned int value = convert_to_int(arguments);
        return std::make_unique<instructions::IntegerLiteral>(value);
      });

    register_supplier(
      "\\",
      [](const std::string& arguments) -> auto { return std::make_unique<instructions::StringLiteral>(arguments); });

    register_supplier(
      ">",
      [](const std::string& arguments) -> auto { return std::make_unique<instructions::LabelReference>(arguments); });

    register_supplier(
      "=", [](const std::string& arguments) -> auto {
        return std::make_unique<instructions::VariableAssignment>(arguments);
      });

    register_supplier(
      "$", [](const std::string& arguments) -> auto {
        return std::make_unique<instructions::VariableReference>(arguments);
      });

    //#endregion

    //#region Integer operations

    register_supplier(
      "add", [](const std::string& arguments) -> auto { return std::make_unique<instructions::Add>(); });
    register_supplier(
      "sub", [](const std::string& arguments) -> auto { return std::make_unique<instructions::Subtract>(); });
    register_supplier(
      "mul", [](const std::string& arguments) -> auto { return std::make_unique<instructions::Multiply>(); });
    register_supplier(
      "div", [](const std::string& arguments) -> auto { return std::make_unique<instructions::Divide>(); });
    register_supplier(
      "mod", [](const std::string& arguments) -> auto { return std::make_unique<instructions::Modulo>(); });
    register_supplier(
      "neg", [](const std::string& arguments) -> auto { return std::make_unique<instructions::Negate>(); });
    register_supplier(
      "abs", [](const std::string& arguments) -> auto { return std::make_unique<instructions::AbsoluteValue>(); });
    register_supplier(
      "inc", [](const std::string& arguments) -> auto { return std::make_unique<instructions::Increment>(); });
    register_supplier(
      "dec", [](const std::string& arguments) -> auto { return std::make_unique<instructions::Decrement>(); });

    //#endregion

    //#region String operations

    register_supplier(
      "dup", [](const std::string& arguments) -> auto { return std::make_unique<instructions::Duplicate>(); });
    register_supplier(
      "rev", [](const std::string& arguments) -> auto { return std::make_unique<instructions::Reverse>(); });
    register_supplier(
      "slc", [](const std::string& arguments) -> auto { return std::make_unique<instructions::Substring>(); });
    register_supplier(
      "idx", [](const std::string& arguments) -> auto { return std::make_unique<instructions::Index>(); });
    register_supplier(
      "cat", [](const std::string& arguments) -> auto { return std::make_unique<instructions::Concatenate>(); });
    register_supplier(
      "len", [](const std::string& arguments) -> auto { return std::make_unique<instructions::Length>(); });
    register_supplier(
      "rot", [](const std::string& arguments) -> auto { return std::make_unique<instructions::Rot13>(); });
    register_supplier(
      "enl", [](const std::string& arguments) -> auto { return std::make_unique<instructions::Newline>(); });

    //#endregion

    //#region Tests & jumps

    register_supplier(
      "gto", [](const std::string& arguments) -> auto { return std::make_unique<instructions::Goto>(); });
    register_supplier(
      "geq", [](const std::string& arguments) -> auto { return std::make_unique<instructions::GotoIfEqual>(); });
    register_supplier(
      "gne", [](const std::string& arguments) -> auto { return std::make_unique<instructions::GotoIfNotEqual>(); });
    register_supplier(
      "glt", [](const std::string& arguments) -> auto { return std::make_unique<instructions::GotoIfLess>(); });
    register_supplier(
      "gle", [](const std::string& arguments) -> auto { return std::make_unique<instructions::GotoIfLessOrEqual>(); });
    register_supplier(
      "ggt", [](const std::string& arguments) -> auto { return std::make_unique<instructions::GotoIfGreater>(); });
    register_supplier(
      "gge",
      [](const std::string& arguments) -> auto { return std::make_unique<instructions::GotoIfGreaterOrEqual>(); });

    //#endregion

    //#region Functions

    register_supplier(
      "fun", [](const std::string& arguments) -> auto { return std::make_unique<instructions::Function>(); });
    register_supplier(
      "ret", [](const std::string& arguments) -> auto { return std::make_unique<instructions::Return>(); });

    //#endregion

    //#region End

    register_supplier(
      "end", [](const std::string& arguments) -> auto { return std::make_unique<instructions::End>(); });

    //#endregion
  }

  std::unique_ptr<interpreter::Instruction> DefaultInstructionFactory::create(const std::string& instruction,
                                                                              const std::string& arguments) const {
    if (!has_supplier(instruction)) throw UnknownInstructionException {instruction};
    InstructionSupplier supplier = _suppliers.at(instruction);
    return supplier(arguments);
  }

  void DefaultInstructionFactory::register_supplier(const std::string& instruction, InstructionSupplier supplier) {
    _suppliers[instruction] = supplier;
  }

  bool DefaultInstructionFactory::has_supplier(const std::string& instruction) const {
    return _suppliers.find(instruction) != _suppliers.end();
  }

} // namespace krul::parser