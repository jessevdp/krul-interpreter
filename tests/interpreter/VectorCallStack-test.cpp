#include "interpreter/VectorCallStack.h"

#include <catch.hpp>

using namespace krul::interpreter;

SCENARIO("VectorCallStack behaves like a stack", "[VectorCallStack]") {
  VectorCallStack stack;

  GIVEN("1 item pushed onto the stack") {
    line_t item = 1;
    stack.push(item);

    WHEN("pop is called for the first time") {
      line_t value = stack.pop();

      THEN("the item is returned") {
        REQUIRE(value == item);
      }
    }
    AND_WHEN("pop is called for the second time") {
      stack.pop();

      THEN("it throws") {
        REQUIRE_THROWS_AS(stack.pop(), std::out_of_range);
      }
    }
  }

  GIVEN("2 items pushed onto the stack") {
    line_t item1 = 1;
    line_t item2 = 2;
    stack.push(item1);
    stack.push(item2);

    WHEN("pop is called for the first time") {
      line_t value = stack.pop();

      THEN("the item that was added last is returned") {
        REQUIRE(value == item2);
      }
    }
    AND_WHEN("pop is called for the second time") {
      stack.pop();
      line_t value = stack.pop();

      THEN("the item that was first added is returned") {
        REQUIRE(value == item1);
      }
    }
  }
}