#include "interpreter/Context.h"
#include "interpreter/Stack.h"
#include "interpreter/instructions/Subtract.h"

#include <catch.hpp>
#include <fakeit.hpp>

using namespace krul::interpreter;
using namespace krul::interpreter::instructions;
using namespace fakeit;

TEST_CASE("Subtract pops two integers off the Stack, subtracts the second from the first, and pushes the result back "
          "on the Stack",
          "[Subtract]") {
  int a = 5;
  int b = 2;

  Mock<Stack> stackMock;
  Fake(Method(stackMock, push));
  When(Method(stackMock, pop_as_int)).Return(b).Return(a);

  Mock<Context> contextMock;
  When(Method(contextMock, stack)).AlwaysReturn(stackMock.get());

  Subtract instruction;
  instruction.execute(contextMock.get());

  Verify(Method(stackMock, pop_as_int)).Twice();
  Verify(Method(stackMock, push).Using("3")).Once();
}