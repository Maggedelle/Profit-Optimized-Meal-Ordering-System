#include "profit_wrap.hpp"
#include "string"


Courier courier = {"Test", 123,123,123};
Order order;

void hello2() {
  order.id = "hello";
  courier.longitude = 1;
  std::cout << courier << std::endl;
  std::cout << order << std::endl;
}
