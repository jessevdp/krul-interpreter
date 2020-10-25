#include "interpreter/Context.h"
#include "interpreter/Stack.h"
#include "interpreter/instructions/LabelReference.h"

#include <catch.hpp>
#include <fakeit.hpp>

using namespace krul::interpreter;
using namespace krul::interpreter::instructions;
using namespace fakeit;

TEST_CASE("LabelReference pushes its label value (line #) (converted to a string) to the Stack", "[LabelReference]") {
  Mock<Stack> stackMock;
  Fake(Method(stackMock, push));
  Mock<Context> contextMock;
  When(Method(contextMock, stack)).AlwaysReturn(stackMock.get());

  LabelReference instruction {11};
  instruction.execute(contextMock.get());

  Verify(Method(stackMock, push).Using("11")).Once();
}