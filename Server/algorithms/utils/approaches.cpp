#include "approaches.hpp"

namespace approach {

  std::tuple<std::vector<std::pair<Courier, Order>>, int, int> greedy_approach (std::vector<Courier> couriers, const std::vector<Order>& orders) {
    std::vector<std::pair<Courier, Order>> greedy_assignment {};
    int total_assignment_reward = 0;
    int total_assignment_travel_time = 0;

    for(const auto& order: orders) {
      const auto AC = utils::get_available_couriers(couriers, order);

      if(AC.size() == 0)
        continue;

      const auto courier = AC[0];
      total_assignment_reward += order.reward;
      total_assignment_travel_time += utils::calc_time_needed(utils::calc_distance(courier, order), courier.speed);
      greedy_assignment.push_back(std::make_pair(courier,order));
      string id_to_remove = courier.id;

      couriers.erase(std::remove_if(begin(couriers),end(couriers),[id_to_remove](const auto& courier) {
            return courier.id == id_to_remove;
            }), end(couriers));
    }

    return {greedy_assignment, total_assignment_reward, total_assignment_travel_time};
  }
  
  std::tuple<std::vector<std::pair<Courier, Order>>, int, int> random_approach (std::vector<Courier> couriers, const std::vector<Order>& orders){
    std::vector<std::pair<Courier, Order>> greedy_assignment {};
    int total_assignment_reward = 0;
    int total_assignment_travel_time = 0;

    for(const auto& order: orders) {
      const auto AC = utils::get_available_couriers(couriers, order);

      if(AC.size() == 0)
        continue;

      string id_to_remove = AC[0].id;
      couriers.erase(std::remove_if(begin(couriers),end(couriers),[id_to_remove](const auto& courier) {
            return courier.id == id_to_remove;
            }), end(couriers));
    }

    return {greedy_assignment, total_assignment_reward, total_assignment_travel_time};
  }
}
