#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <string>
#include "utils/approaches.hpp"

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

namespace py = pybind11;

PYBIND11_MODULE(profit_module, m) {
  m.doc() = R"pbdoc(
      Pybind11 example plugin
        -----------------------

      .. currentmodule:: cmake_example

      .. autosummary::
         :toctree: _generate

         add
         subtract
  )pbdoc";

  py::class_<Courier>(m,"Courier")
    .def(py::init<
        const string&,
        const long double&,
        const long double&,
        const int&,
        const int&>())
    .def_readwrite("id", &Courier::id)
    .def_readwrite("latitude", &Courier::latitude)
    .def_readwrite("longitude", &Courier::longitude)
    .def_readwrite("speed", &Courier::speed)
    .def_readwrite("max_distance", &Courier::max_distance)
    .def("__repr__", [](const Courier &courier) {
          return "Courier id: " + courier.id + "";
        });

  py::class_<Order>(m,"Order")
    .def(py::init<
        const string&,
        const long double&,
        const long double&,
        const long double&,
        const long double&,
        const int&,
        const int&,
        const int&>())
    .def_readwrite("id", &Order::id)
    .def_readwrite("order_lat", &Order::order_lat)
    .def_readwrite("order_long", &Order::order_long)
    .def_readwrite("restaurant_lat", &Order::restaurant_lat)
    .def_readwrite("restaurant_long", &Order::restaurant_long)
    .def_readwrite("expected_delivery", &Order::expected_delivery)
    .def_readwrite("deadline", &Order::deadline)
    .def_readwrite("reward", &Order::reward)
    .def("__repr__", [](const Order &order) {
          return "Order id: " + order.id + "";
        });

  py::class_<Assignment>(m,"Assignment")
    .def(py::init<
        const Courier&,
        const Order&,
        const int&,
        const int&>())
    .def_readwrite("courier", &Assignment::courier)
    .def_readwrite("order", &Assignment::order)
    .def_readwrite("distance", &Assignment::distance)
    .def_readwrite("travel_time", &Assignment::travel_time)
    .def("__repr__", [](const Assignment& a) {
          return "Courier id: " + a.courier.id + ", order id: " + a.order.id + ", distance: " + std::to_string(a.distance)  + ", travel time: " + std::to_string(a.travel_time); 
        });

  m.def("greedy_approach", &approach::greedy_approach, "The greedy approach to assigning couriers to orders");
  m.def("random_approach", &approach::random_approach, "The random approach to assigning couriers to orders");
  m.def("create_couriers", &utils::create_couriers, "Create N amnount of couriers");
  m.def("create_orders", &utils::create_orders, "Create N amount of orders");

  m.attr("__version__") = "0.5";
}
