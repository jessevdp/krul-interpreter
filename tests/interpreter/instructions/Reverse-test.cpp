#include "interpreter/Context.h"
#include "interpreter/Stack.h"
#include "interpreter/instructions/Reverse.h"

#include <catch.hpp>
#include <fakeit.hpp>

using namespace krul::interpreter;
using namespace krul::interpreter::instructions;
using namespace fakeit;

TEST_CASE("Reverse pops one value off the stack, reverses it, and pushes it back on the Stack", "[Reverse]") {
  Mock<Stack> stackMock;
  Fake(Method(stackMock, push));
  When(Method(stackMock, pop)).AlwaysReturn("abc");

  Mock<Context> contextMock;
  When(Method(contextMock, stack)).AlwaysReturn(stackMock.get());

  Reverse instruction;
  instruction.execute(contextMock.get());

  Verify(Method(stackMock, pop)).Once();
  Verify(Method(stackMock, push).Using("cba")).Once();
}
