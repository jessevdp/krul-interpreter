#include "interpreter/Context.h"
#include "interpreter/Stack.h"
#include "interpreter/instructions/AbsoluteValue.h"

#include <catch.hpp>
#include <fakeit.hpp>

using namespace krul::interpreter;
using namespace krul::interpreter::instructions;
using namespace fakeit;

TEST_CASE(
  "AbsoluteValue pops one integer off the Stack, calculates its absolute value, and pushes that back on the Stack",
  "[AbsoluteValue]") {
  Mock<Stack> stackMock;
  Fake(Method(stackMock, push));

  Mock<Context> contextMock;
  When(Method(contextMock, stack)).AlwaysReturn(stackMock.get());

  AbsoluteValue instruction;

  SECTION("positive starting number") {
    int number = 10;
    When(Method(stackMock, pop_as_int)).AlwaysReturn(number);

    instruction.execute(contextMock.get());

    Verify(Method(stackMock, pop_as_int)).Once();
    Verify(Method(stackMock, push).Using("10")).Once();
  }

  SECTION("negative starting number") {
    int number = -5;
    When(Method(stackMock, pop_as_int)).AlwaysReturn(number);

    instruction.execute(contextMock.get());

    Verify(Method(stackMock, pop_as_int)).Once();
    Verify(Method(stackMock, push).Using("5")).Once();
  }
}
