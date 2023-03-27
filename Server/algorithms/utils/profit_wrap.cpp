#include "profit_wrap.hpp"


long double hello2() {
  Courier courier = {"Courier1", 53.32055555555556, -1.7297222222222221, 2, 5};
  Order order = {"Order1", 53.32055555555556, -1.7297222222222221, 53.31861111111111, -1.6997222222222223, 1, 2, 3};
  std::vector<Courier> couriers;
  std::vector<Order> orders;

  couriers.push_back(courier);
  orders.push_back(order);

  const auto [vec_pair, reward] = greedy::greedy_approach(couriers,orders);
  std::cout << reward << std::endl;

  const auto AC = greedy::get_available_couriers(couriers, order);
  std::cout << AC.size() << std::endl;


  long double ans = utils::calc_distance(courier,order);

  return ans;
}
