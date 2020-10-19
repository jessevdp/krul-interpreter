#include "interpreter/Context.h"
#include "interpreter/Stack.h"
#include "interpreter/instructions/Add.h"

#include <catch.hpp>
#include <fakeit.hpp>

using namespace krul::interpreter;
using namespace krul::interpreter::instructions;
using namespace fakeit;

TEST_CASE("Add pops two integers off the Stack, adds them, and pushes the result back on the Stack", "[Add]") {
  int a = 1;
  int b = 2;

  Mock<Stack> stackMock;
  Fake(Method(stackMock, push));
  When(Method(stackMock, pop_as_int)).Return(a).Return(b);

  Mock<Context> contextMock;
  When(Method(contextMock, stack)).AlwaysReturn(stackMock.get());

  Add instruction;
  instruction.execute(contextMock.get());

  Verify(Method(stackMock, pop_as_int)).Twice();
  Verify(Method(stackMock, push).Using("3")).Once();
}