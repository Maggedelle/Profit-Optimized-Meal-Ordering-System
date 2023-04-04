import sys
sys.path.append('build')

import profit_module as pm

courier_test = pm.Courier("Magnus",1,2,1,4)
courier_test1 = pm.Courier("Magnus",1,2,3,4)
courier_test2 = pm.Courier("Magnus",1,2,3,4)
courier_test3 = pm.Courier("Magnus",1,2,3,4)
courier_test4 = pm.Courier("Magnus",1,2,1,4)

couriers = []
couriers.append(courier_test)
couriers.append(courier_test)
couriers.append(courier_test)
couriers.append(courier_test)
couriers.append(courier_test)

print(pm.vec_test(couriers))

print(pm.hello2(courier_test))
