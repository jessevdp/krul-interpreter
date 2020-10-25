#include "interpreter/Context.h"
#include "interpreter/Stack.h"
#include "interpreter/instructions/Rot13.h"

#include <catch.hpp>
#include <fakeit.hpp>

using namespace krul::interpreter;
using namespace krul::interpreter::instructions;
using namespace fakeit;

TEST_CASE("Rot13 pops one value off the stack, applies Rot13 to it, and pushes it back on the Stack", "[Rot13]") {
  Mock<Stack> stackMock;
  Fake(Method(stackMock, push));
  When(Method(stackMock, pop)).AlwaysReturn("abcdefghijklmnopqrstuvwxyz");

  Mock<Context> contextMock;
  When(Method(contextMock, stack)).AlwaysReturn(stackMock.get());

  Rot13 instruction;
  instruction.execute(contextMock.get());

  Verify(Method(stackMock, pop)).Once();
  Verify(Method(stackMock, push).Using("nopqrstuvwxyzabcdefghijklm")).Once();
}
