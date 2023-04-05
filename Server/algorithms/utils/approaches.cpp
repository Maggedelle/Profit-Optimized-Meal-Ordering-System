#include "assignment.hpp"
#include <random>

namespace approach {

  std::tuple<std::vector<Assignment>, int, int> greedy_approach (std::vector<Courier> couriers, const std::vector<Order>& orders) {
    std::vector<Assignment> greedy_assignment {};
    int total_assignment_reward = 0;
    int total_assignment_travel_time = 0;

    for(const auto& order: orders) {
      const auto AC = utils::get_available_couriers(couriers, order);

      if(AC.size() == 0)
        continue;

      const auto courier = AC[0];
      const auto distance = utils::calc_distance(courier, order);
      const auto travel_time = utils::calc_time_needed(distance, courier.speed);

      total_assignment_reward += utils::calc_reward(travel_time, order.expected_delivery, order.deadline, order.reward);
      total_assignment_travel_time += travel_time; 

      Assignment assignment(courier, order, distance, travel_time);

      greedy_assignment.push_back(assignment);
      string id_to_remove = courier.id;

      couriers.erase(std::remove_if(begin(couriers),end(couriers),[id_to_remove](const auto& courier) {
            return courier.id == id_to_remove;
            }), end(couriers));
    }

    return {greedy_assignment, total_assignment_reward, total_assignment_travel_time};
  }
  
  std::tuple<std::vector<Assignment>, int, int> random_approach (std::vector<Courier> couriers, const std::vector<Order>& orders, size_t random_N){
    std::vector<Assignment> random_assignment {};
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
      const auto travel_time = utils::calc_time_needed(distance, courier.speed);

      total_assignment_reward += utils::calc_reward(travel_time, order.expected_delivery, order.deadline, order.reward);
      total_assignment_travel_time += travel_time; 

      Assignment assignment(courier, order, distance, travel_time);

      random_assignment.push_back(assignment);
      const auto id_to_remove = courier.id;

      couriers.erase(std::remove_if(begin(couriers),end(couriers),[id_to_remove](const auto& courier) {
            return courier.id == id_to_remove;
            }), end(couriers));
    }

    return {random_assignment, total_assignment_reward, total_assignment_travel_time};
  }
}
