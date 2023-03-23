#include "profit_wrap.hpp"
#include "string"


long double hello2() {
  Courier courier = {"Courier1", 53.32055555555556, -1.7297222222222221, 2};
  Order order = {"Order1", 53.32055555555556, -1.7297222222222221, 53.31861111111111, -1.6997222222222223, 1, 2, 3};

  long double ans = utils::calc_distance(courier,order);

  return ans;
}
