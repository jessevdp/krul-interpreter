#include "interpreter/Context.h"
#include "interpreter/instructions/End.h"

#include <catch.hpp>
#include <fakeit.hpp>

using namespace krul::interpreter;
using namespace krul::interpreter::instructions;
using namespace fakeit;

TEST_CASE("End calls found_end on the Context", "[End]") {

  Mock<Context> contextMock;
  Fake(Method(contextMock, found_end));

  End instruction;
  instruction.execute(contextMock.get());

  Verify(Method(contextMock, found_end)).Once();
}