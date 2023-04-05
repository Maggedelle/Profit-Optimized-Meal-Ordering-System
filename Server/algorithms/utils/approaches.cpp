#include "approaches.hpp"
#include <random>

namespace approach {

  std::tuple<std::vector<std::tuple<Courier, Order, int, int>>, int, int> greedy_approach (std::vector<Courier> couriers, const std::vector<Order>& orders) {
    std::vector<std::tuple<Courier, Order, int, int>> greedy_assignment {};
    int total_assignment_reward = 0;
    int total_assignment_travel_time = 0;

    for(const auto& order: orders) {
      const auto AC = utils::get_available_couriers(couriers, order);

      if(AC.size() == 0)
        continue;

      const auto courier = AC[0];
      const auto distance = utils::calc_distance(courier, order);
      const auto order_duration = utils::calc_time_needed(distance, courier.speed);

      total_assignment_reward += utils::calc_reward(order_duration, order.expected_delivery, order.deadline, order.reward);
      total_assignment_travel_time += order_duration; 

      greedy_assignment.push_back({courier,order, distance, order_duration});
      string id_to_remove = courier.id;

      couriers.erase(std::remove_if(begin(couriers),end(couriers),[id_to_remove](const auto& courier) {
            return courier.id == id_to_remove;
            }), end(couriers));
    }

    return {greedy_assignment, total_assignment_reward, total_assignment_travel_time};
  }
  
  std::tuple<std::vector<std::tuple<Courier, Order, int, int>>, int, int> random_approach (std::vector<Courier> couriers, const std::vector<Order>& orders, size_t random_N){
    std::vector<std::tuple<Courier, Order, int, int>> random_assignment {};
    int total_assignment_reward = 0;
    int total_assignment_travel_time = 0;

    for(const auto& order: orders) {
      const auto AC = utils::get_available_couriers(couriers, order);

      if(AC.size() == 0)
        continue;

      std::vector<Courier> random_select {};
      std::sample(
          begin(AC),
          end(AC),
          std::back_inserter(random_select),
          random_N,
          std::mt19937{std::random_device{}()}
          );

      const auto courier = random_select[0];
      const auto distance = utils::calc_distance(courier, order);
      const auto order_duration = utils::calc_time_needed(distance, courier.speed);

      total_assignment_reward += utils::calc_reward(order_duration, order.expected_delivery, order.deadline, order.reward);
      total_assignment_travel_time += order_duration; 

      random_assignment.push_back({courier,order, distance, order_duration});
      const auto id_to_remove = courier.id;

      couriers.erase(std::remove_if(begin(couriers),end(couriers),[id_to_remove](const auto& courier) {
            return courier.id == id_to_remove;
            }), end(couriers));
    }

    return {random_assignment, total_assignment_reward, total_assignment_travel_time};
  }
}
