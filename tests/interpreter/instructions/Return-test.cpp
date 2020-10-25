#include "interpreter/CallStack.h"
#include "interpreter/Context.h"
#include "interpreter/instructions/Return.h"

#include <catch.hpp>
#include <fakeit.hpp>

using namespace krul::interpreter;
using namespace krul::interpreter::instructions;
using namespace fakeit;

TEST_CASE("Return pops one line off the CallStack, and executes a go_to_line on the Context", "[Return]") {
  line_t line = 1;

  Mock<CallStack> callStackMock;
  When(Method(callStackMock, pop)).AlwaysReturn(line);

  Mock<Context> contextMock;
  Fake(Method(contextMock, go_to_line));
  When(Method(contextMock, call_stack)).AlwaysReturn(callStackMock.get());

  Return instruction;
  instruction.execute(contextMock.get());

  Verify(Method(callStackMock, pop)).Once();
  Verify(Method(contextMock, go_to_line).Using(line)).Once();
}
