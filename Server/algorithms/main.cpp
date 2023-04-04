#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
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

  m.def("greedy_approach", &approach::greedy_approach, "Awesome hello");

  m.attr("__version__") = "0.1";
}
