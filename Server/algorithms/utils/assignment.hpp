#include "utility.hpp"

class Assignment {
  public:
    Courier courier {};
    Order order {};
    int distance {};
    int travel_time {};

    Assignment(Courier _courier, Order _order,int _distance, int _travel_time) : 
      courier(_courier),
      order(_order),
      distance(_distance),
      travel_time(_travel_time) {}
};
