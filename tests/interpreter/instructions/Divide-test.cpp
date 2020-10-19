#include "interpreter/Context.h"
#include "interpreter/Stack.h"
#include "interpreter/instructions/Divide.h"

#include <catch.hpp>
#include <fakeit.hpp>

using namespace krul::interpreter;
using namespace krul::interpreter::instructions;
using namespace fakeit;

TEST_CASE(
  "Divide pops two integers off the Stack, divides the first by the second, and pushes the result back on the Stack",
  "[Divide]") {
  Mock<Stack> stackMock;
  Fake(Method(stackMock, push));
  Mock<Context> contextMock;
  When(Method(contextMock, stack)).AlwaysReturn(stackMock.get());

  Divide instruction;

  SECTION("integer result is handled correctly") {
    int a = 2;
    int b = 6;

    When(Method(stackMock, pop_as_int)).Return(a).Return(b);

    instruction.execute(contextMock.get());

    Verify(Method(stackMock, pop_as_int)).Twice();
    Verify(Method(stackMock, push).Using("3")).Once();
  }

  SECTION("floating point result is truncated") {
    int a = 2;
    int b = 9;

    When(Method(stackMock, pop_as_int)).Return(a).Return(b);

    instruction.execute(contextMock.get());

    Verify(Method(stackMock, pop_as_int)).Twice();
    Verify(Method(stackMock, push).Using("4")).Once();
  }
}
