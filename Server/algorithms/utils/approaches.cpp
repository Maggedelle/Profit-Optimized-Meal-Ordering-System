#include "approaches.hpp"

namespace approach {

  std::tuple<std::vector<std::pair<Courier, Order>>, int> greedy_approach (std::vector<Courier> couriers,const std::vector<Order>& orders) {
    std::vector<std::pair<Courier, Order>> greedy_assignment {};
    int total_assignment_reward = 0;

    for(const auto& order: orders) {
      const auto AC = utils::get_available_couriers(couriers, order);

      if(AC.size() == 0)
        continue;

      total_assignment_reward += order.reward;
      greedy_assignment.push_back(std::make_pair(AC[0],order));
      string id_to_remove = AC[0].id;

      couriers.erase(std::remove_if(begin(couriers),end(couriers),[id_to_remove](const auto& courier) {
            return courier.id == id_to_remove;
            }), end(couriers));
    }

    return {greedy_assignment, total_assignment_reward};
  }
}
