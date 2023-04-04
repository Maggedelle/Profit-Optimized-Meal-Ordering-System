#include "profit_wrap.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

int factorial (int number) {return number <= 1 ? number : factorial(number - 1) * number; }

TEST_CASE("Testing factorial function") {
  SUBCASE("Factorial function") {
    CHECK(factorial(1) == 1);
    CHECK(factorial(2) == 2);
    CHECK(factorial(3) == 6);
  }
  SUBCASE("Testing Hello2") {
    CHECK(hello2() == "Hello");
  }
}


