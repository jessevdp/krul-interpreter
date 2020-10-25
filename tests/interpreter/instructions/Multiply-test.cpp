#include "interpreter/Context.h"
#include "interpreter/Stack.h"
#include "interpreter/instructions/Multiply.h"

#include <catch.hpp>
#include <fakeit.hpp>

using namespace krul::interpreter;
using namespace krul::interpreter::instructions;
using namespace fakeit;

TEST_CASE("Multiply pops two integers off the Stack, multiplies them, and pushes the result back on the Stack",
          "[Multiply]") {
  int a = 3;
  int b = 3;

  Mock<Stack> stackMock;
  Fake(Method(stackMock, push));
  When(Method(stackMock, pop_as_int)).Return(a).Return(b);

  Mock<Context> contextMock;
  When(Method(contextMock, stack)).AlwaysReturn(stackMock.get());

  Multiply instruction;
  instruction.execute(contextMock.get());

  Verify(Method(stackMock, pop_as_int)).Twice();
  Verify(Method(stackMock, push).Using("9")).Once();
}