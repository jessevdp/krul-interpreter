#include "interpreter/MapVariableRegistry.h"

#include <catch.hpp>

using namespace krul::interpreter;
using namespace krul::interpreter::exception;

SCENARIO("MapVariableRegistry stores variables", "[MapVariableRegistry]") {
  MapVariableRegistry registry;
  variable_t variable_name = "my-variable";

  GIVEN("a variable is set") {
    value_t value = "my-value";
    registry.set(variable_name, value);

    THEN("it can be retrieved") {
      REQUIRE(registry.get(variable_name) == value);
    }

    WHEN("it is set again") {
      value_t new_value = "my-new-value";
      registry.set(variable_name, new_value);

      THEN("the value is overwritten") {
        REQUIRE(registry.get(variable_name) == new_value);
      }
    }
  }

  GIVEN("a variable is NOT set") {
    THEN("retrieving it throws an UndefinedVariableException") {
      REQUIRE_THROWS_AS(registry.get(variable_name), UndefinedVariableException);
    }
  }
}