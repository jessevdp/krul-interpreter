#include "interpreter/instructions/VariableReference.h"
#include "interpreter/Context.h"
#include "interpreter/Stack.h"

#include <catch.hpp>
#include <fakeit.hpp>

using namespace krul::interpreter;
using namespace krul::interpreter::instructions;
using namespace fakeit;

TEST_CASE("VariableReference pushes the value of a variable onto the Stack", "[VariableReference]") {
variable_t variable {"my-variable"};
value_t value {"my-value"};

Mock<VariableRegistry> variableRegistryMock;
When(Method(variableRegistryMock, get)).AlwaysReturn(value);

Mock<Stack> stackMock;
Fake(Method(stackMock, push));

Mock<Context> contextMock;
When(Method(contextMock, variables)).AlwaysReturn(variableRegistryMock.get());
When(Method(contextMock, stack)).AlwaysReturn(stackMock.get());

VariableReference instruction {variable};
instruction.execute(contextMock.get());

Verify(Method(variableRegistryMock, get).Using(variable)).Once();
Verify(Method(stackMock, push).Using(value)).Once();
}