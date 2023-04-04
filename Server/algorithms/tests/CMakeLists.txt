cmake_minimum_required(VERSION 3.0)
project(testbuild)

add_library(profit_module_cpp STATIC ../utils/courier.cpp ../utils/order.cpp ../utils/profit_wrap.cpp doctest.h) 

add_executable(tests tests.cpp)
target_compile_features(tests PRIVATE cxx_std_20)
target_link_libraries(tests PRIVATE profit_module_cpp)
