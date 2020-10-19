#include "interpreter/instructions/IntegerLiteral.h"
#include "interpreter/Context.h"
#include "interpreter/Stack.h"

#include <catch.hpp>
#include <fakeit.hpp>

using namespace krul::interpreter;
using namespace krul::interpreter::instructions;
using namespace fakeit;

TEST_CASE("IntegerLiteral pushes its integer value (converted to a string) to the Stack", "[IntegerLiteral]") {
  Mock<Stack> stackMock;
  Fake(Method(stackMock, push));
  Mock<Context> contextMock;
  When(Method(contextMock, stack)).AlwaysReturn(stackMock.get());

  IntegerLiteral instruction {1000};
  instruction.execute(contextMock.get());

  Verify(Method(stackMock, push).Using("1000")).Once();
}