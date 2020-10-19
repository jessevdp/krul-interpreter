#include "interpreter/Context.h"
#include "interpreter/Stack.h"
#include "interpreter/instructions/Duplicate.h"

#include <catch.hpp>
#include <fakeit.hpp>

using namespace krul::interpreter;
using namespace krul::interpreter::instructions;
using namespace fakeit;

TEST_CASE("Duplicate duplicates the value at the top of the Stack", "[Duplicate]") {
  value_t value {"my-value"};

  Mock<Stack> stackMock;
  Fake(Method(stackMock, push));
  When(Method(stackMock, peek)).AlwaysReturn(value);

  Mock<Context> contextMock;
  When(Method(contextMock, stack)).AlwaysReturn(stackMock.get());

  Duplicate instruction;
  instruction.execute(contextMock.get());

  Verify(Method(stackMock, peek)).Once();
  Verify(Method(stackMock, push).Using(value)).Once();
}
