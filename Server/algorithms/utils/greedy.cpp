#include "greedy.hpp"
#include "iostream"
#include "experimental/vector"

namespace greedy {

  std::tuple<std::vector<std::pair<Courier, Order>>, int> greedy_approach (std::vector<Courier> couriers,const std::vector<Order>& orders) {
    std::vector<std::pair<Courier, Order>> greedy_assignment {};
    int total_assignment_reward = 0;

    for(const auto& order: orders) {
      const auto AC = get_available_couriers(couriers, order);

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

  std::vector<Courier> get_available_couriers(const std::vector<Courier>& couriers, const Order& order) {
    std::vector<Courier> AC{};
    Order copy_order = order;
    auto within_distance =  [copy_order](Courier courier) { return courier.max_distance <= utils::calc_distance(courier, copy_order);};

    for(const auto& courier : couriers
                            | std::views::filter(within_distance)) {
      AC.push_back(courier);
    }

    sort(begin(AC),end(AC), [copy_order](const auto& lhs, const auto& rhs){
        const auto dist_lhs = utils::calc_distance(lhs, copy_order);
        const auto dist_rhs = utils::calc_distance(rhs, copy_order);
        const auto time_needed_lhs = utils::calc_time_needed(dist_lhs, lhs.speed);
        const auto time_needed_rhs = utils::calc_time_needed(dist_rhs, rhs.speed);

        return time_needed_lhs < time_needed_rhs;
        });

    return AC;
  }
}
