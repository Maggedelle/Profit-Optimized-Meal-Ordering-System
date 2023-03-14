cmake_minimum_required(VERSION 3.4...3.18)
project(algorithms LANGUAGES CXX)


add_library(test_file STATIC algo_functions/test_file.cpp)
set_target_properties(test_file PROPERTIES POSITION_INDEPENDENT_CODE ON)

add_subdirectory(pybind11)
pybind11_add_module(algorithms binder.cpp)
target_link_libraries(algorithms PRIVATE test_file)
