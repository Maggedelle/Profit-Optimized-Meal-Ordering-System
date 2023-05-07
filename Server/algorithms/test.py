import sys
sys.path.append('build')

import profit_module as pm

couriers = pm.create_couriers(1000);
orders = pm.create_orders(100)

assignment, reward, travel_time = pm.greedy_approach(couriers, orders)
assignment1, reward1, travel_time1 = pm.random_approach(couriers, orders, 1)

print("Greedy assignment:", reward, travel_time)
print("Random assignment:", reward1, travel_time1)
