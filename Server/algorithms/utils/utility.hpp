#include "vector"
#include "cmath"
#include <ranges>
#include "order.hpp"
#include "courier.hpp"

namespace utils {
  long double calc_distance(const Courier& courier, const Order& order);
  long double to_radians(const long double& degree);
  std::vector<Courier> get_available_couriers (const std::vector<Courier>& couriers, const Order& order);
  int calc_time_needed(const long double& dist, const int& velocity);
  int calc_reward(const int& order_duration, const int& expected_time, const int& deadline, const int& reward);
}
