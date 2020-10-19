#include "interpreter/Context.h"
#include "interpreter/Stack.h"
#include "interpreter/instructions/StringLiteral.h"

#include <catch.hpp>
#include <fakeit.hpp>

using namespace krul::interpreter;
using namespace krul::interpreter::instructions;
using namespace fakeit;

TEST_CASE("StringLiteral pushes its value to the Stack", "[StringLiteral]") {
  Mock<Stack> stackMock;
  Fake(Method(stackMock, push));
  Mock<Context> contextMock;
  When(Method(contextMock, stack)).AlwaysReturn(stackMock.get());

  std::string value {"string literal"};

  StringLiteral instruction {value};
  instruction.execute(contextMock.get());

  Verify(Method(stackMock, push).Using(value)).Once();
}