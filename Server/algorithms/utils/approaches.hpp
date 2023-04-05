#include "vector"
#include "utility"
#include "tuple"
#include "ranges"
#include "assignment.hpp"
#include "experimental/vector"
#include <algorithm>
#include <random>

namespace approach {
  std::tuple<std::vector<Assignment>, int, int> greedy_approach (std::vector<Courier> couriers,const std::vector<Order>& orders);

  std::tuple<std::vector<Assignment>, int, int> random_approach (std::vector<Courier> couriers, const std::vector<Order>& orders, size_t random_N = 1);
} 
