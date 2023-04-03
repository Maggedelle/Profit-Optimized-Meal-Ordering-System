#include "profit_wrap.hpp"

string hello2() {
  Courier courier = {"Courier1", 53.32055555555556, -1.7297222222222221, 20000, 4500};
  Courier courier1 = {"Courier2", 53.32055555555556, -1.7297222222222221, 10000, 5000};
  Courier courier2 = {"Courier2", 53.32055555555556, -1.7297222222222221, 14000, 5000};
  Order order = {"Order", 53.32055555555556, -1.7297222222222221, 53.31861111111111, -1.6997222222222223, 1, 20, 3};
  Order order2 = {"Order2", 55.32055555555556, -1.7297222222222221, 53.31861111111111, -1.6997222222222223, 1, 45, 100};
  Order order1 = {"Order1", 53.32055555555556, -1.7297222222222221, 53.31861111111111, -1.6997222222222223, 1, 40, 7};
  std::vector<Courier> couriers;
  std::vector<Order> orders;

  couriers.push_back(courier);
  couriers.push_back(courier1);
  couriers.push_back(courier2);
  orders.push_back(order);
  orders.push_back(order2);
  orders.push_back(order1);

  const auto [vec_pair, reward] = approach::greedy_approach(couriers,orders);
  std::cout << "Reward for the 3 orders: " <<  reward << std::endl;
  std::cout << "Possible orders to fulfill: " << orders.size() << std::endl;
  std::cout << "Used number of orders: " << vec_pair.size() << std::endl;
  std::cout << "Orders used: ";
  for(const auto& [courier, order] : vec_pair) {
    std::cout << order.id << " ";
  }
  std::cout << std::endl << std::endl;

  std::cout << "Show that get_available_couriers sorts on max_distance and fastest to fulfill" << std::endl << std::endl;
  std::cout << "Before: ";
  std::cout << "First element speed: " << couriers[0].speed << ", second element speed: " << couriers[1].speed << std::endl;
  const auto AC = utils::get_available_couriers(couriers, order);
  std::cout << "End: ";
  std::cout << "First element speed: " << AC[0].speed << ", second element speed: " << AC[1].speed << std::endl;

  return "Hej, Magnus. Nu virker greedy tror jeg";
}
