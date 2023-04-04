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

    Order(string _id, long double _order_lat, long double _order_long, long double _restaurant_lat, long double _restaurant_long, int _expected_delivery, int _deadline, int _reward) : 
      id(_id), 
      order_lat(_order_lat), 
      order_long(_order_long),
      restaurant_lat(_restaurant_lat),
      restaurant_long(_restaurant_long),
      expected_delivery(_expected_delivery),
      deadline(_deadline),
      reward(_reward) {}

    friend std::ostream& operator<<(std::ostream&, const Order&);
};
