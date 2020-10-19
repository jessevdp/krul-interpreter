#include "interpreter/Context.h"
#include "interpreter/Stack.h"
#include "interpreter/instructions/Index.h"

#include <catch.hpp>
#include <fakeit.hpp>

using namespace krul::interpreter;
using namespace krul::interpreter::instructions;
using namespace fakeit;

TEST_CASE("Index pops 2 values off the Stack (index, value), and pushes the character at index of value back on the Stack", "[Index]") {
  Mock<Stack> stackMock;
  Fake(Method(stackMock, push));
  When(Method(stackMock, pop_as_int)).Return(8);
  When(Method(stackMock, pop)).Return("0123456789");

  Mock<Context> contextMock;
  When(Method(contextMock, stack)).AlwaysReturn(stackMock.get());

  Index instruction;
  instruction.execute(contextMock.get());

  Verify(Method(stackMock, pop_as_int)).Once();
  Verify(Method(stackMock, pop)).Once();
  Verify(Method(stackMock, push).Using("8")).Once();
}
