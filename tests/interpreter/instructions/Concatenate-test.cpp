#include "interpreter/Context.h"
#include "interpreter/Stack.h"
#include "interpreter/instructions/Concatenate.h"

#include <catch.hpp>
#include <fakeit.hpp>

using namespace krul::interpreter;
using namespace krul::interpreter::instructions;
using namespace fakeit;

TEST_CASE(
  "Concatenate pops 2 values off the Stack, adds the second to the first, and pushes the result back on the Stack",
  "[Concatenate]") {
  Mock<Stack> stackMock;
  Fake(Method(stackMock, push));
  When(Method(stackMock, pop)).Return("hello").Return("world");

  Mock<Context> contextMock;
  When(Method(contextMock, stack)).AlwaysReturn(stackMock.get());

  Concatenate instruction;
  instruction.execute(contextMock.get());

  Verify(Method(stackMock, pop)).Twice();
  Verify(Method(stackMock, push).Using("helloworld")).Once();
}
