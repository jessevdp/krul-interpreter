#include "interpreter/Context.h"
#include "interpreter/Stack.h"
#include "interpreter/instructions/GotoIfLess.h"

#include <catch.hpp>
#include <fakeit.hpp>

using namespace krul::interpreter;
using namespace krul::interpreter::instructions;
using namespace fakeit;

TEST_CASE("GotoIfLess pops 3 values off the Stack (label, a, b), interprets a & b as int, if (a < b) it executes a "
          "go_to_line on the Context",
          "[GotoIfLess]") {
  label_t label = 1;

  Mock<Stack> stackMock;
  When(Method(stackMock, pop_as_label)).AlwaysReturn(label);

  Mock<Context> contextMock;
  Fake(Method(contextMock, go_to_line));
  When(Method(contextMock, stack)).AlwaysReturn(stackMock.get());

  GotoIfLess instruction;

  SECTION("a < b -> jump") {
    When(Method(stackMock, pop_as_int)).Return(100).Return(1);
    instruction.execute(contextMock.get());
    Verify(Method(contextMock, go_to_line).Using(label)).Once();
  }

  SECTION("a = b -> no jump") {
    When(Method(stackMock, pop_as_int)).Return(1).Return(1);
    instruction.execute(contextMock.get());
    Verify(Method(contextMock, go_to_line)).Never();
  }

  SECTION("a > b -> no jump") {
    When(Method(stackMock, pop_as_int)).Return(1).Return(100);
    instruction.execute(contextMock.get());
    Verify(Method(contextMock, go_to_line)).Never();
  }

  Verify(Method(stackMock, pop_as_label)).Once();
  Verify(Method(stackMock, pop_as_int)).Twice();
}
