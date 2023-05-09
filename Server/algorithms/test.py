import time
import sys
sys.path.append('build')

from profit_module import *

# Test: Average reward, travel time and orders completed. N = [10,100,1000,10000], with the average of 100 tests per N.

N = [10,50,200,500,1000,2000,5000]
results_greedy = []
results_random = []
start = time.time()

for n in N:
    total_reward_greedy = 0
    total_reward_random = 0
    total_travel_time_greedy = 0
    total_travel_time_random = 0
    total_assignments_completed_greedy = 0
    total_assignments_completed_random = 0
    total_reward_possible = 0
    n_start = time.time()

    for _ in range(100):
        couriers = create_couriers(n)
        orders = create_orders(n)

        for order in orders:
            total_reward_possible += order.reward

        assignment_greedy, reward_greedy, travel_time_greedy = greedy_approach(couriers, orders)
        assignment_random, reward_random, travel_time_random = random_approach(couriers, orders, 1)

        total_reward_greedy += reward_greedy 
        total_reward_random += reward_random
        total_travel_time_greedy += travel_time_greedy
        total_travel_time_random += travel_time_random
        total_assignments_completed_greedy += len(assignment_greedy)
        total_assignments_completed_random += len(assignment_random)

    avg_total_reward_greedy = total_reward_greedy / 100
    avg_total_reward_random = total_reward_random / 100
    avg_total_travel_time_greedy = total_travel_time_greedy / 100
    avg_total_travel_time_random = total_travel_time_random / 100
    avg_total_assignments_completed_greedy = total_assignments_completed_greedy / 100 
    avg_total_assignments_completed_random = total_assignments_completed_random / 100 
    avg_total_reward_possible = total_reward_possible / 100

    results_greedy.append((avg_total_reward_greedy, avg_total_travel_time_greedy, avg_total_assignments_completed_greedy))
    results_random.append((avg_total_reward_random, avg_total_travel_time_random, avg_total_assignments_completed_random))
    n_end = time.time()
    print("Results for n =",n)
    print("Test duratation",(n_end-n_start)/60,"minutes")
    print("Max reward possible:", avg_total_reward_possible)
    print("   Greedy results:")
    print("     Reward achieved      :",avg_total_reward_greedy)
    print("     Travel time          :",avg_total_travel_time_greedy)
    print("     Assignments completed:",avg_total_assignments_completed_greedy)
    print("   Random results:")
    print("     Reward achieved      :",avg_total_reward_random)
    print("     Travel time          :",avg_total_travel_time_random)
    print("     Assignments completed:",avg_total_assignments_completed_random)
    print("------------------------------------------")



end = time.time()
print("Total test duration:",(end-start)/60,"minutes")
print(results_greedy)
print(results_random)
