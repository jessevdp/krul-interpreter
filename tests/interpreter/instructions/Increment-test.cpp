#include "interpreter/instructions/Increment.h"
#include "interpreter/Context.h"
#include "interpreter/Stack.h"

#include <catch.hpp>
#include <fakeit.hpp>

using namespace krul::interpreter;
using namespace krul::interpreter::instructions;
using namespace fakeit;

TEST_CASE("Increment pops one integer off the Stack, increments it by 1, and pushes that back on the Stack", "[Increment]") {
  Mock<Stack> stackMock;
  Fake(Method(stackMock, push));
  When(Method(stackMock, pop_as_int)).AlwaysReturn(10);

  Mock<Context> contextMock;
  When(Method(contextMock, stack)).AlwaysReturn(stackMock.get());

  Increment instruction;
  instruction.execute(contextMock.get());

  Verify(Method(stackMock, pop_as_int)).Once();
  Verify(Method(stackMock, push).Using("11")).Once();

}
