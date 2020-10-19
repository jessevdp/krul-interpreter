#include "interpreter/instructions/Modulo.h"
#include "interpreter/Context.h"
#include "interpreter/Stack.h"

#include <catch.hpp>
#include <fakeit.hpp>

using namespace krul::interpreter;
using namespace krul::interpreter::instructions;
using namespace fakeit;

TEST_CASE("Modulo pops two integers off the Stack, calculates 'second % first', and pushes the result back on the Stack", "[Modulo]") {
  int a = 3;
  int b = 10;

  Mock<Stack> stackMock;
  Fake(Method(stackMock, push));
  When(Method(stackMock, pop_as_int))
    .Return(a)
    .Return(b);

  Mock<Context> contextMock;
  When(Method(contextMock, stack)).AlwaysReturn(stackMock.get());

  Modulo instruction;
  instruction.execute(contextMock.get());

  Verify(Method(stackMock, pop_as_int)).Twice();
  Verify(Method(stackMock, push).Using("1")).Once();
}