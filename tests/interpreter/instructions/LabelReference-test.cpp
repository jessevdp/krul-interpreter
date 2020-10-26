#include "interpreter/Context.h"
#include "interpreter/LabelRegistry.h"
#include "interpreter/Stack.h"
#include "interpreter/instructions/LabelReference.h"

#include <catch.hpp>
#include <fakeit.hpp>

using namespace krul::interpreter;
using namespace krul::interpreter::instructions;
using namespace fakeit;

TEST_CASE("LabelReference retrieves its label value (line #) and pushes it (converted to a string) to the Stack",
          "[LabelReference]") {
  label_name_t label_name {"my-label"};

  Mock<LabelRegistry> labelRegistryMock;
  When(Method(labelRegistryMock, get).Using(label_name)).AlwaysReturn(11);

  Mock<Stack> stackMock;
  Fake(Method(stackMock, push));
  Mock<Context> contextMock;
  When(Method(contextMock, stack)).AlwaysReturn(stackMock.get());
  When(Method(contextMock, labels)).AlwaysReturn(labelRegistryMock.get());

  LabelReference instruction {label_name};
  instruction.execute(contextMock.get());

  Verify(Method(stackMock, push).Using("11")).Once();
}