#include "vector"
#include "cmath"
#include "courier.hpp"
#include "order.hpp"

namespace utils {
  long double calc_distance(const Courier& courier, const Order& order);
  long double to_radians(const long double& degree);
  int calc_time_needed(const long double& dist, const int& velocity);
}
