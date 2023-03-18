#include <pybind11/pybind11.h>
#include "utils/courier.hpp"
#include "utils/profit_wrap.hpp"

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

    m.def("add", &add, R"pbdoc(
        Add two numbers

        Some other explanation about the add function.
    )pbdoc");

    m.def("hello", &hello, "Awesome doc");
    m.def("hello2", &hello2, "Awesome hello");

    m.attr("__version__") = "0.0.1";
}
