cmake_minimum_required(VERSION 3.4...3.18)
project(profit_maximization)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(profit_module_cpp STATIC utils/courier.cpp utils/order.cpp utils/utility.cpp utils/greedy.cpp utils/profit_wrap.cpp) 
set_target_properties(profit_module_cpp PROPERTIES POSITION_INDEPENDENT_CODE ON)

add_subdirectory(pybind11)
pybind11_add_module(profit_module main.cpp)
target_link_libraries(profit_module PRIVATE profit_module_cpp)
