#include "greedy.hpp"

namespace greedy {

  std::tuple<std::vector<std::pair<Courier, Order>>, int> greedy_approach (const std::vector<Courier>& couriers, std::vector<Order>& orders) {
    std::vector<std::pair<Courier, Order>> greedy_assignment {};

    greedy_assignment.push_back(std::make_pair(couriers[0],orders[0]));

    return {greedy_assignment, 12};
  }

  std::vector<Courier> get_available_couriers(const std::vector<Courier>& couriers, const Order& order) {
    std::vector<Courier> AC{};
    Order copy_order = order;
    auto within_distance =  [copy_order](Courier courier) { return courier.max_distance <= utils::calc_distance(courier, copy_order);};

    for(const auto& courier : couriers
                            | std::views::filter(within_distance)) {
      AC.push_back(courier);
    }

    return AC;
  }
}
