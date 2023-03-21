#include "vector"
#include "cmath"

namespace utils {
  long double calc_dist(const Courier& courier, const Order& order);
  long double to_radians(const long double& degree);
  int calc_time_needed(const long double& dist, const int& velocity);
}
