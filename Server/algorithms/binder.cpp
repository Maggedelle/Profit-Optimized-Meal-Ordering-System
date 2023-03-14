#include <pybind11/pybind11.h>
#include "algo_functions/test_file.h"


namespace py = pybind11;

PYBIND11_MODULE(cmake_example, m) {
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
    )pbdoc");

    m.def("subtract", &sub, R"pbdoc(
        Subtract two numbers
    )pbdoc");

    m.def("square", &square, R"pbdoc(
        square a number
    )pbdoc");

    m.def("hello_py", &hello, R"pbdoc(
        Say hello to Python
    )pbdoc");

}
