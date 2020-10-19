#include "interpreter/instructions/VariableAssignment.h"
#include "interpreter/Context.h"
#include "interpreter/Stack.h"

#include <catch.hpp>
#include <fakeit.hpp>

using namespace krul::interpreter;
using namespace krul::interpreter::instructions;
using namespace fakeit;

TEST_CASE("VariableAssignment pops the latest value off the Stack and sets its variable equal to this value", "[VariableAssignment]") {
  variable_t variable {"my-variable"};
  value_t value {"my-value"};

  Mock<VariableRegistry> variableRegistryMock;
  Fake(Method(variableRegistryMock, set));

  Mock<Stack> stackMock;
  When(Method(stackMock, pop)).AlwaysReturn(value);

  Mock<Context> contextMock;
  When(Method(contextMock, variables)).AlwaysReturn(variableRegistryMock.get());
  When(Method(contextMock, stack)).AlwaysReturn(stackMock.get());

  VariableAssignment instruction {variable};
  instruction.execute(contextMock.get());

  Verify(Method(stackMock, pop)).Once();
  Verify(Method(variableRegistryMock, set).Using(variable, value)).Once();
}