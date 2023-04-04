import sys
sys.path.append('build')

import profit_module as pm

courier_test = pm.Courier("Magnus",0,0,0,0)
order = pm.Order("Magnus1",0,0,0,0,0,0,0)
print(order)
print(courier_test, courier_test.latitude, courier_test.longitude, courier_test.speed, courier_test.max_distance)

print(pm.hello2())
