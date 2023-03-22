#include "utility.hpp"

constexpr long double R = 6371;

namespace utils {

  long double calc_distance(const Courier& courier, const Order& order) {

    // Convert longitude and latitude coordinates to radians
    courier_lat = to_radians(courier.latitude);
    courier_long = to_radians(courier.longitude);
    order_lat = to_radians(order.order_lat);
    order_long = to_radians(order.order_long);
    restaurant_lat = to_radians(order.restaurant_lat);
    restaurant_long = to_radians(order.restaurant_long);

    // Haversine formula en.wikipedia.org/wiki/Haversine_formula
    // Need to change courier_order - the courier does not move straight to the order,
    // but moves to the restaurant first.
    // TODO: Change courier_order to courier_restaurant. We are moving from the courier to the restaurant.
    // TODO: Change order_restaurant to restaurant_order. We are moving from the restaurant to the order.
    long double courier_order_lat = order_lat - courier_lat;
    long double courier_order_long = order_long - courier_long;
    long double order_restaurant_lat = restaurant_lat - courier_lat;
    long double order_restaurant_long = restaurant_long - courier_long;

    long double distance1 {};
    long double distance2 {};

    distance1 = pow(sin(courier_order_lat / 2), 2) + cos(courier_lat) * cos(order_lat) * pow(sin(courier_order_long / 2), 2);
    distance2 = pow(sin(order_restaurant_lat / 2), 2) + cos(restaurant_lat) * cos(restaurant_long) * pow(sin(order_restaurant_long / 2), 2);

    distance1 = 2 * asin(sqrt(distance1));
    distance2 = 2 * asin(sqrt(distance2));

    // Handle the earths curvature
    distance1 *= R;
    distance2 *= R;

    return distance1 + distance2;
  }
}
