#include "iosfwd"
#include "string"
#include "vector"

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

    friend std::ostream& operator<<(std::ostream&, const Order&);
};
