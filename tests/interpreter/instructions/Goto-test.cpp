#include "interpreter/Context.h"
#include "interpreter/Stack.h"
#include "interpreter/instructions/Goto.h"

#include <catch.hpp>
#include <fakeit.hpp>

using namespace krul::interpreter;
using namespace krul::interpreter::instructions;
using namespace fakeit;

TEST_CASE("Goto pops one value off the Stack, interprets it as a label, and executes a go_to_line on the Context", "[Goto]") {
  label_t label = 1;

  Mock<Stack> stackMock;
  When(Method(stackMock, pop_as_label)).AlwaysReturn(label);

  Mock<Context> contextMock;
  Fake(Method(contextMock, go_to_line));
  When(Method(contextMock, stack)).AlwaysReturn(stackMock.get());

  Goto instruction;
  instruction.execute(contextMock.get());

  Verify(Method(stackMock, pop_as_label)).Once();
  Verify(Method(contextMock, go_to_line).Using(label)).Once();
}
