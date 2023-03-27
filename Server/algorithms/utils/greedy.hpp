#include "vector"
#include "utility"
#include "tuple"
#include "utility.hpp"
#include "ranges"

namespace greedy {
  std::tuple<std::vector<std::pair<Courier, Order>>, int> greedy_approach (std::vector<Courier> couriers,const std::vector<Order>& orders);
  std::vector<Courier> get_available_couriers (const std::vector<Courier>& couriers, const Order& order);
} 
