#include "interpreter/Context.h"
#include "interpreter/Stack.h"
#include "interpreter/instructions/Decrement.h"

#include <catch.hpp>
#include <fakeit.hpp>

using namespace krul::interpreter;
using namespace krul::interpreter::instructions;
using namespace fakeit;

TEST_CASE("Decrement pops one integer off the Stack, decrements it by 1, and pushes that back on the Stack",
          "[Decrement]") {
  Mock<Stack> stackMock;
  Fake(Method(stackMock, push));
  When(Method(stackMock, pop_as_int)).AlwaysReturn(10);

  Mock<Context> contextMock;
  When(Method(contextMock, stack)).AlwaysReturn(stackMock.get());

  Decrement instruction;
  instruction.execute(contextMock.get());

  Verify(Method(stackMock, pop_as_int)).Once();
  Verify(Method(stackMock, push).Using("9")).Once();
}
