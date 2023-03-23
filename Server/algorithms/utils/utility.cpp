#include "utility.hpp"

constexpr long double R = 6371;

namespace utils {

  long double calc_distance(const Courier& courier, const Order& order) {

    // Convert longitude and latitude coordinates to radians
    long double courier_lat = to_radians(courier.latitude);
    long double courier_long = to_radians(courier.longitude);
    long double order_lat = to_radians(order.order_lat);
    long double order_long = to_radians(order.order_long);
    long double restaurant_lat = to_radians(order.restaurant_lat);
    long double restaurant_long = to_radians(order.restaurant_long);

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

    return total_distance;
  }

  long double to_radians(const long double& degree) {
    long double one_degree = (M_PI) / 180;
    long double radian = one_degree * degree;

    return radian;
  }

  int calc_time_needed(const long double& dist, const int& velocity) {
    return 0;
  }
}
