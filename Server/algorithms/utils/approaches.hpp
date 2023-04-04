#include "vector"
#include "utility"
#include "tuple"
#include "utility.hpp"
#include "ranges"
#include "experimental/vector"
#include <algorithm>
#include <random>

namespace approach {
  std::tuple<std::vector<std::pair<Courier, Order>>, int, int> greedy_approach (std::vector<Courier> couriers,const std::vector<Order>& orders);

  std::tuple<std::vector<std::pair<Courier, Order>>, int, int> random_approach (std::vector<Courier> couriers, const std::vector<Order>& orders, size_t random_N = 1);
} 