#include "hello.h"

#include <catch.hpp>

TEST_CASE("hello returns the string 'Hello World!'") {
  REQUIRE(hello() == "Hello World!");
}