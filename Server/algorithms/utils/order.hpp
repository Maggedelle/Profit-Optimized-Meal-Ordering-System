#include "iosfwd"
#include "string"
#include "vector"
#include "utility"
#include "courier.hpp"

using std::string;

class Order {
  public:
    string id {};
    long double order_lat {};
    long double order_long {};
    long double restaurant_lat {};
    long double restaurant_long {};
    int expected_delivery {};
    int deadline {};
    int reward {};
    std::vector<std::pair<Courier, int>> available_couriers;

    friend std::ostream& operator<<(std::ostream&, const Order&);
};
