#include "interpreter/Context.h"
#include "interpreter/Stack.h"
#include "interpreter/instructions/Length.h"

#include <catch.hpp>
#include <fakeit.hpp>

using namespace krul::interpreter;
using namespace krul::interpreter::instructions;
using namespace fakeit;

TEST_CASE("Length pops one value off the Stack and pushes its length back on to the Stack", "[Length]") {
  Mock<Stack> stackMock;
  Fake(Method(stackMock, push));
  When(Method(stackMock, pop)).AlwaysReturn("abc");

  Mock<Context> contextMock;
  When(Method(contextMock, stack)).AlwaysReturn(stackMock.get());

  Length instruction;
  instruction.execute(contextMock.get());

  Verify(Method(stackMock, pop)).Once();
  Verify(Method(stackMock, push).Using("3")).Once();
}
