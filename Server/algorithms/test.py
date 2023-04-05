import sys
sys.path.append('build')

import profit_module as pm

courier_test = pm.Courier("Courier1", 53.32055555555556, -1.7297222222222221, 20000, 4500)
courier_test1 = pm.Courier("Courier2", 53.32055555555556, -1.7297222222222221, 10000, 5000)
courier_test2 = pm.Courier("Courier2", 53.32055555555556, -1.7297222222222221, 14000, 5000)
courier_test3 = pm.Courier("Courier3", 53.32055555555556, -1.7297222222222221, 16000, 5000)
courier_test4 = pm.Courier("Courier4", 53.32055555555556, -1.7297222222222221, 8000, 5000)
courier_test5 = pm.Courier("Courier5", 53.32055555555556, -1.7297222222222221, 4000, 5000)

order_test = pm.Order("Order", 53.32055555555556, -1.7297222222222221, 53.31861111111111, -1.6997222222222223, 1, 20, 3)
order_test2 = pm.Order("Order2", 53.32055555555556, -1.7297222222222221, 53.31861111111111, -1.6997222222222223, 1, 45, 100)
order_test1 = pm.Order("Order1", 53.32055555555556, -1.7297222222222221, 53.31861111111111, -1.6997222222222223, 1, 40, 7)

couriers = []
couriers.append(courier_test)
couriers.append(courier_test1)
couriers.append(courier_test2)
couriers.append(courier_test3)
couriers.append(courier_test4)

orders = []
orders.append(order_test)
orders.append(order_test2)
orders.append(order_test1)

assignment, reward, distance = pm.greedy_approach(couriers, orders)
assignment1, reward1, distance1 = pm.random_approach(couriers, orders, 1)
print("Greedy assignment:", reward, distance, assignment[0][2], assignment[0][3])
print(assignment)
print("Random assignment:", reward1, distance1, assignment1[0][2], assignment1[0][3])
print(assignment1)
