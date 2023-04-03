#include "vector"
#include "utility"
#include "tuple"
#include "utility.hpp"
#include "ranges"
#include "experimental/vector"

namespace greedy {
  std::tuple<std::vector<std::pair<Courier, Order>>, int> greedy_approach (std::vector<Courier> couriers,const std::vector<Order>& orders);
} 