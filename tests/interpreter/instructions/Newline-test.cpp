#include "interpreter/Context.h"
#include "interpreter/Stack.h"
#include "interpreter/instructions/Newline.h"

#include <catch.hpp>
#include <fakeit.hpp>

using namespace krul::interpreter;
using namespace krul::interpreter::instructions;
using namespace fakeit;

TEST_CASE("Newline pops one value off the stack, appends '\\n', and pushes it back on the Stack", "[Newline]") {
  Mock<Stack> stackMock;
  Fake(Method(stackMock, push));
  When(Method(stackMock, pop)).AlwaysReturn("hello");

  Mock<Context> contextMock;
  When(Method(contextMock, stack)).AlwaysReturn(stackMock.get());

  Newline instruction;
  instruction.execute(contextMock.get());

  Verify(Method(stackMock, pop)).Once();
  Verify(Method(stackMock, push).Using("hello\n")).Once();
}
