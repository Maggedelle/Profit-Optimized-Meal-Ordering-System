#include "iosfwd"
#include "string"

using std::string;

class Order {
  public:
    string id {};
    long double order_long {};
    long double order_lat {};
    long double restaurant_long {};
    long double restaurant_lat {};
    int expected_delivery {};
    int deadline {};
    int reward {};

    friend std::ostream& operator<<(std::ostream&, const Order&);
};
