#include "profit_wrap.hpp"

string hello2() {
  Courier courier = {"Courier1", 53.32055555555556, -1.7297222222222221, 20000, 4500};
  Courier courier1 = {"Courier2", 53.32055555555556, -1.7297222222222221, 10000, 5000};
  Courier courier2 = {"Courier2", 53.32055555555556, -1.7297222222222221, 14000, 5000};
  Courier courier3 = {"Courier3", 53.32055555555556, -1.7297222222222221, 16000, 5000};
  Courier courier4 = {"Courier4", 53.32055555555556, -1.7297222222222221, 8000, 5000};
  Courier courier5 = {"Courier5", 53.32055555555556, -1.7297222222222221, 4000, 5000};
  Order order = {"Order", 53.32055555555556, -1.7297222222222221, 53.31861111111111, -1.6997222222222223, 1, 20, 3};
  Order order2 = {"Order2", 53.32055555555556, -1.7297222222222221, 53.31861111111111, -1.6997222222222223, 1, 45, 100};
  Order order1 = {"Order1", 53.32055555555556, -1.7297222222222221, 53.31861111111111, -1.6997222222222223, 1, 40, 7};
  std::vector<Courier> couriers;
  std::vector<Order> orders;

  couriers.push_back(courier);
  couriers.push_back(courier1);
  couriers.push_back(courier2);
  couriers.push_back(courier3);
  couriers.push_back(courier4);
  couriers.push_back(courier5);
  orders.push_back(order);
  orders.push_back(order2);
  orders.push_back(order1);

  const auto [vec_pair, reward, travel_time] = approach::greedy_approach(couriers,orders);
  std::cout << "-------Greedy------" << std::endl;
  std::cout << "Reward for the 3 orders: " <<  reward << std::endl;
  std::cout << "travel time for the 3 orders: " <<  travel_time << std::endl;
  std::cout << "Possible orders to fulfill: " << orders.size() << std::endl;
  std::cout << "Used number of orders: " << vec_pair.size() << std::endl;
  std::cout << "Orders used: ";
  for(const auto& [courier, order] : vec_pair) {
    std::cout << order.id << " ";
  }
  std::cout << std::endl << std::endl;

  const auto [vec_pair1, reward1, travel_time1] = approach::random_approach(couriers,orders);
  std::cout << "------Random------" << std::endl;
  std::cout << "Reward for the 3 orders: " <<  reward1 << std::endl;
  std::cout << "travel time for the 3 orders: " <<  travel_time1 << std::endl;
  std::cout << "Possible orders to fulfill: " << orders.size() << std::endl;
  std::cout << "Used number of orders: " << vec_pair1.size() << std::endl;
  std::cout << "Orders used: ";
  for(const auto& [courier, order] : vec_pair1) {
    std::cout << order.id << " ";
  }

  std::cout << "\n" << std::endl;

  return "Hej, Magnus. Nu virker greedy tror jeg";
}
