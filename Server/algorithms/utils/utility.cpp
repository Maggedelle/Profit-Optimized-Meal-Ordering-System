#include "utility.hpp"
#include "iostream"

constexpr long double R = 6371;
constexpr int penalty   =    1;

namespace utils {

  long double calc_distance(const Courier& courier, const Order& order) {

    // Convert longitude and latitude coordinates to radians
    const auto courier_lat = to_radians(courier.latitude);
    const auto courier_long = to_radians(courier.longitude);
    const auto order_lat = to_radians(order.order_lat);
    const auto order_long = to_radians(order.order_long);
    const auto restaurant_lat = to_radians(order.restaurant_lat);
    const auto restaurant_long = to_radians(order.restaurant_long);

    // Haversine formula en.wikipedia.org/wiki/Haversine_formula
    // First get the difference between the courier and the restaurant
    long double courier_restaurant_lat = restaurant_lat - courier_lat;
    long double courier_restaurant_long = restaurant_long - courier_long;
    // Get the difference between the restaurant and order
    long double restaurant_order_lat = order_lat - restaurant_lat;
    long double restaurant_order_long = order_long - restaurant_long;


    long double distance1 = pow(sin(courier_restaurant_lat/ 2), 2) + cos(courier_lat) * cos(restaurant_lat) * pow(sin(courier_restaurant_long/ 2), 2);
    long double distance2 = pow(sin(restaurant_order_lat/ 2), 2) + cos(restaurant_lat) * cos(order_lat) * pow(sin(restaurant_order_long/ 2), 2);

    distance1 = 2 * asin(sqrt(distance1));
    distance2 = 2 * asin(sqrt(distance2));

    // Handle the earths curvature
    long double total_distance = (distance1 + distance2) * R;

    // Convert from kilometers to meters
    total_distance *= 1000;

    return total_distance;
  }

  long double to_radians(const long double& degree) {
    long double one_degree = (M_PI) / 180;
    long double radian = one_degree * degree;

    return radian;
  }

  int calc_time_needed(const long double& dist, const int& velocity) {
    int time_needed = (dist / velocity) * 60;

    return time_needed;
  }

  std::vector<Courier> get_available_couriers(const std::vector<Courier>& couriers, const Order& order) {
    std::vector<Courier> AC{};
    Order copy_order = order;
    auto within_distance =  [copy_order](Courier courier) { return calc_distance(courier, copy_order) <= courier.max_distance;};

    for(const auto& courier : couriers
                            | std::views::filter(within_distance)) {
      AC.push_back(courier);
    }

    sort(begin(AC),end(AC), [copy_order](const auto& lhs, const auto& rhs){
        const auto dist_lhs = calc_distance(lhs, copy_order);
        const auto dist_rhs = calc_distance(rhs, copy_order);
        const auto time_needed_lhs = calc_time_needed(dist_lhs, lhs.speed);
        const auto time_needed_rhs = calc_time_needed(dist_rhs, rhs.speed);

        return time_needed_lhs < time_needed_rhs;
        });

    return AC;
  }

  int calc_reward(const int& order_duration, const int& expected_time, const int& deadline, const int& reward) {
    int total_reward {};

    if(order_duration < expected_time) {
      total_reward = reward;
    }else if(expected_time < order_duration && order_duration < deadline) {
      total_reward = reward - (penalty * (order_duration - expected_time));
    }else {
      total_reward = 0;
    }

    return total_reward;
  }
}
