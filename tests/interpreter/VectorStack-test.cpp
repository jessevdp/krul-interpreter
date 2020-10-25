#include "interpreter/VectorStack.h"
#include "interpreter/exception/TypeConversionException.h"

#include <catch.hpp>

using namespace krul::interpreter;
using namespace krul::interpreter::exception;

SCENARIO("VectorStack behaves like a stack", "[VectorStack]") {
  VectorStack stack;

  GIVEN("1 item pushed onto the stack") {
    value_t item = "item";
    stack.push(item);

    WHEN("pop is called for the first time") {
      value_t value = stack.pop();

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

    WHEN("peek is called for the first time") {
      value_t value = stack.peek();

      THEN("the item is returned") {
        REQUIRE(value == item);
      }
    }
    AND_WHEN("peek is called a bunch of times") {
      THEN("the same item is returned") {
        REQUIRE(stack.peek() == item);
        REQUIRE(stack.peek() == item);
        REQUIRE(stack.peek() == item);
        REQUIRE(stack.peek() == item);
      }
    }

    WHEN("pop is called after peek") {
      value_t peekValue = stack.peek();
      value_t popValue = stack.pop();

      THEN("the same item is returned") {
        REQUIRE(peekValue == item);
        REQUIRE(popValue == item);
      }
    }
    AND_WHEN("peek is called after pop") {
      stack.pop();

      THEN("it throws") {
        REQUIRE_THROWS_AS(stack.peek(), std::out_of_range);
      }
    }
  }

  GIVEN("2 items pushed onto the stack") {
    value_t item1 = "item1";
    value_t item2 = "item2";
    stack.push(item1);
    stack.push(item2);

    WHEN("pop is called for the first time") {
      value_t value = stack.pop();

      THEN("the item that was added last is returned") {
        REQUIRE(value == item2);
      }
    }
    AND_WHEN("pop is called for the second time") {
      stack.pop();
      value_t value = stack.pop();

      THEN("the item that was first added is returned") {
        REQUIRE(value == item1);
      }
    }
  }
}

SCENARIO("VectorStack can convert values to int", "[VectorStack]") {
  VectorStack stack;

  GIVEN("a value that can be interpreted as an int") {
    stack.push("10");

    WHEN("pop_as_int is called") {
      int value = stack.pop_as_int();

      THEN("the value is converted to int before being returned") {
        REQUIRE(value == 10);
      }
    }

    WHEN("peek_as_int is called") {
      int value = stack.peek_as_int();

      THEN("the value is converted to int before being returned") {
        REQUIRE(value == 10);
      }
    }
  }

  GIVEN("a value that can NOT be interpreted as an int") {
    stack.push("foo");

    WHEN("pop_as_int is called") {
      THEN("it throws a TypeConversionException") {
        REQUIRE_THROWS_AS(stack.pop_as_int(), TypeConversionException);
      }
    }

    WHEN("peek_as_int is called") {
      THEN("it throws a TypeConversionException") {
        REQUIRE_THROWS_AS(stack.peek_as_int(), TypeConversionException);
      }
    }
  }
}

SCENARIO("VectorStack can convert values to label_t", "[VectorStack]") {
  VectorStack stack;

  GIVEN("a value that can be interpreted as a label") {
    stack.push("10");

    WHEN("pop_as_label is called") {
      label_t value = stack.pop_as_label();

      THEN("the value is converted to int before being returned") {
        REQUIRE(value == 10);
      }
    }

    WHEN("peek_as_label is called") {
      label_t value = stack.peek_as_label();

      THEN("the value is converted to int before being returned") {
        REQUIRE(value == 10);
      }
    }
  }

  GIVEN("a negative numeric value") {
    stack.push("-10");

    WHEN("pop_as_label is called") {
      THEN("it throws a TypeConversionException") {
        REQUIRE_THROWS_AS(stack.pop_as_label(), TypeConversionException);
      }
    }

    WHEN("peek_as_label is called") {
      THEN("it throws a TypeConversionException") {
        REQUIRE_THROWS_AS(stack.peek_as_label(), TypeConversionException);
      }
    }
  }

  GIVEN("a value that can NOT be interpreted as a label_t") {
    stack.push("foo");

    WHEN("pop_as_label is called") {
      THEN("it throws a TypeConversionException") {
        REQUIRE_THROWS_AS(stack.pop_as_label(), TypeConversionException);
      }
    }

    WHEN("peek_as_label is called") {
      THEN("it throws a TypeConversionException") {
        REQUIRE_THROWS_AS(stack.peek_as_label(), TypeConversionException);
      }
    }
  }
}