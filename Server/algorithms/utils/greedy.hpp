#include "vector"
#include "utility"
#include "utility.hpp"

namespace greedy {
std::vector<std::pair<Courier, Order>> greedy_approach (std::vector<Courier> couriers, std::vector<Order> orders);
std::vector<Courier> get_available_couriers (const Order& order, const std::vector<Courier>& couriers);
}
