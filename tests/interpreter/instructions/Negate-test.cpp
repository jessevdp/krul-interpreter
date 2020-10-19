#include "interpreter/instructions/Negate.h"
#include "interpreter/Context.h"
#include "interpreter/Stack.h"

#include <catch.hpp>
#include <fakeit.hpp>

using namespace krul::interpreter;
using namespace krul::interpreter::instructions;
using namespace fakeit;

TEST_CASE("Negate pops one integer off the Stack, negates it, and pushes it back on the Stack", "[Negate]") {
  Mock<Stack> stackMock;
  Fake(Method(stackMock, push));

  Mock<Context> contextMock;
  When(Method(contextMock, stack)).AlwaysReturn(stackMock.get());

  Negate instruction;

  SECTION("positive starting number") {
    int number = 10;
    When(Method(stackMock, pop_as_int)).AlwaysReturn(number);

    instruction.execute(contextMock.get());

    Verify(Method(stackMock, pop_as_int)).Once();
    Verify(Method(stackMock, push).Using("-10")).Once();
  }

  SECTION("negative starting number") {
    int number = -5;
    When(Method(stackMock, pop_as_int)).AlwaysReturn(number);

    instruction.execute(contextMock.get());

    Verify(Method(stackMock, pop_as_int)).Once();
    Verify(Method(stackMock, push).Using("5")).Once();
  }
}
