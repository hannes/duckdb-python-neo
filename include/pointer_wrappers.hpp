#pragma once

#include "duckdb_python.hpp"

namespace duckdb_python {
    template<typename T> T* Unwrap(PyObject *self, bool silent = false) {
        if (!PyCapsule_IsValid(self, "TODO")) {
            if (!silent) {
                PyErr_SetString(PyExc_ValueError,"The capsule is invalid");
            }
            return nullptr;
        }
        auto ptr = static_cast<T*>(PyCapsule_GetPointer(self,"TODO"));
        if (!ptr) {
            if (!silent) {
                PyErr_SetString(PyExc_ValueError,"The pointer is NULL");
            }
            return nullptr;
        }
        return ptr;
    }

    template <typename T> static PyObject* Free(PyObject* self, PyObject *) {
        auto ptr = Unwrap<T>(self, true);
        PyMem_Free(ptr);
        return Py_None;
    }

    template <typename T> static void Destroy(PyObject* self) {
        Free<T>(self, nullptr);
    }


    template <typename T> static PyObject* Alloc(PyObject *, PyObject *) {
        auto ptr = static_cast<T*>( PyMem_Malloc(sizeof(T)));
        if (!ptr) {
            PyErr_NoMemory();
        }
        return PyCapsule_New(ptr, "TODO", Destroy<T>);
    }
}