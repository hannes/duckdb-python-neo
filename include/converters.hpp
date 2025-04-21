#pragma once
#include "duckdb_python.hpp"
#include "pointer_wrappers.hpp"

namespace duckdb_python {


    template <typename T> static T FromPy(PyObject* self) {
        static_assert(false, "Can't FromPy this type");
    }

    template <> const char* FromPy(PyObject* self) {
        Py_ssize_t size;
        return PyUnicode_AsUTF8AndSize(self, &size);
    }

    template <> char** FromPy(PyObject* self) {
        return Unwrap<char*>(self);
    }

    template <> const char** FromPy(PyObject* self) {
        return Unwrap<const char*>(self);
    }

    template <> unsigned long FromPy(PyObject* self) {
        return PyLong_AsUnsignedLongLong(self);
    }

    template <typename T> static PyObject* ToPy(T obj) {
        static_assert(false, "Can't ToPy this type");
    }

    template <> PyObject* ToPy(duckdb_state obj) {
        return PyLong_FromLong(obj);
    }

    template <> PyObject* ToPy(unsigned long obj) {
        return PyLong_FromUnsignedLongLong(obj);
    }

    template <> PyObject* ToPy(const char* obj) {
        return PyUnicode_FromString(obj);
    }

    template <> PyObject* ToPy(duckdb_instance_cache self) {
        return PyCapsule_New(self, "instance_cache", nullptr);
    }



}