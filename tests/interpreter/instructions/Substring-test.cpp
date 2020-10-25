#include "interpreter/Context.h"
#include "interpreter/Stack.h"
#include "interpreter/instructions/Substring.h"

#include <catch.hpp>
#include <fakeit.hpp>

using namespace krul::interpreter;
using namespace krul::interpreter::instructions;
using namespace fakeit;

TEST_CASE("Substring pops 3 values off the Stack (to, from, value), and pushes the substring from,to of value back on "
          "the Stack",
          "[Substring]") {
  Mock<Stack> stackMock;
  Fake(Method(stackMock, push));
  When(Method(stackMock, pop_as_int)).Return(5).Return(0);
  When(Method(stackMock, pop)).Return("hello world");

  Mock<Context> contextMock;
  When(Method(contextMock, stack)).AlwaysReturn(stackMock.get());

  Substring instruction;
  instruction.execute(contextMock.get());

  Verify(Method(stackMock, pop_as_int)).Twice();
  Verify(Method(stackMock, pop)).Once();
  Verify(Method(stackMock, push).Using("hello")).Once();
}
