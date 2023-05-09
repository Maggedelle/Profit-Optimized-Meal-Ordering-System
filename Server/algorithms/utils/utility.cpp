#include "utility.hpp"
#include "iostream"
#include <random>
#include <string>

constexpr long double R = 6371;
constexpr int penalty   =    1;
constexpr int speeds[]  = {12000,20000,40000};

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

  std::vector<Courier> create_couriers(const int N) {
    std::random_device rand;
    std::mt19937 gen(rand());
    std::uniform_real_distribution<> dist_cords_lat(53.32055555555556,53.34055555555556);
    std::uniform_real_distribution<> dist_cords(-1.7697222222222221,-1.6497222222222223);
    std::uniform_int_distribution<> dist_vehicle(0,2); 
    std::uniform_int_distribution<> dist_distance(2000,8000);
    
    std::vector<Courier> couriers {};

    for(int i = 0; i < N; i++) {
      Courier courier;
      courier.id = std::to_string(i+1);
      courier.latitude = dist_cords_lat(gen);
      courier.longitude = dist_cords(gen);
      courier.speed = speeds[dist_vehicle(gen)];
      courier.max_distance = dist_distance(gen);

      couriers.push_back(courier);
    }

    return couriers;
  }

  std::vector<Order> create_orders(const int N) {
    std::random_device rand;
    std::mt19937 gen(rand());
    std::uniform_real_distribution<> dist_cords_long(-1.7697222222222221,-1.6497222222222223);
    std::uniform_real_distribution<> dist_cords_lat(53.32055555555556,53.34055555555556);
    std::uniform_int_distribution<> dist_reward(75,150);
    std::uniform_int_distribution<> dist_expected_delivery(30,45);

    std::vector<Order> orders {};

    for(int i = 0; i < N; i++) {
      Order order {};
      order.id = std::to_string(i+1);
      order.order_lat = dist_cords_lat(gen);
      order.order_long = dist_cords_long(gen);
      order.restaurant_lat = dist_cords_lat(gen);
      order.restaurant_long = dist_cords_long(gen);
      order.expected_delivery = dist_expected_delivery(gen);
      order.reward = dist_reward(gen);


      std::uniform_int_distribution<> dist_deadline(order.expected_delivery+1, order.expected_delivery+20);
      order.deadline = dist_deadline(gen);

      orders.push_back(order);
    }

    return orders;
  }
}
