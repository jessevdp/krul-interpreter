#include "interpreter/Context.h"
#include "interpreter/Stack.h"
#include "interpreter/instructions/GotoIfNotEqual.h"

#include <catch.hpp>
#include <fakeit.hpp>

using namespace krul::interpreter;
using namespace krul::interpreter::instructions;
using namespace fakeit;

TEST_CASE(
  "GotoIfNotEqual pops 3 values off the Stack (label, a, b), if (a != b) it executes a go_to_line on the Context",
  "[GotoIfNotEqual]") {
  label_t label = 1;

  Mock<Stack> stackMock;
  When(Method(stackMock, pop_as_label)).AlwaysReturn(label);

  Mock<Context> contextMock;
  Fake(Method(contextMock, go_to_line));
  When(Method(contextMock, stack)).AlwaysReturn(stackMock.get());

  GotoIfNotEqual instruction;

  SECTION("a == b -> no jump") {
    When(Method(stackMock, pop)).Return("hello").Return("hello");
    instruction.execute(contextMock.get());
    Verify(Method(contextMock, go_to_line)).Never();
  }

  SECTION("a != b -> jump") {
    When(Method(stackMock, pop)).Return("hello").Return("not hello");
    instruction.execute(contextMock.get());
    Verify(Method(contextMock, go_to_line).Using(label)).Once();
  }

  Verify(Method(stackMock, pop_as_label)).Once();
  Verify(Method(stackMock, pop)).Twice();
}
