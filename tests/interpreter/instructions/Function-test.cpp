#include "interpreter/CallStack.h"
#include "interpreter/Context.h"
#include "interpreter/Stack.h"
#include "interpreter/instructions/Function.h"

#include <catch.hpp>
#include <fakeit.hpp>

using namespace krul::interpreter;
using namespace krul::interpreter::instructions;
using namespace fakeit;

TEST_CASE("Function pushes the current line + 1 to the call stack, pops one value off the stack and interprets it as "
          "label, and executes a go_to_line to that label on the Context",
          "[Function]") {
  label_t label = 10;

  Mock<CallStack> callStackMock;
  Fake(Method(callStackMock, push));

  Mock<Stack> stackMock;
  When(Method(stackMock, pop_as_label)).AlwaysReturn(label);

  Mock<Context> contextMock;
  Fake(Method(contextMock, go_to_line));
  When(Method(contextMock, current_line)).AlwaysReturn(1);
  When(Method(contextMock, call_stack)).AlwaysReturn(callStackMock.get());
  When(Method(contextMock, stack)).AlwaysReturn(stackMock.get());

  Function instruction;
  instruction.execute(contextMock.get());

  Verify(Method(callStackMock, push).Using(2)).Once();
  Verify(Method(stackMock, pop_as_label)).Once();
  Verify(Method(contextMock, go_to_line).Using(label)).Once();
}
