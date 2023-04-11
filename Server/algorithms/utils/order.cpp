#include "order.hpp"
#include "iostream"

std::ostream& operator<<(std::ostream& os, const Order& order) {
  os << order.id << ", " << order.deadline << ", " << order.expected_delivery;
  return os;
}
