#pragma once
#include "duckdb_python.hpp"
#include "converters.hpp"

namespace duckdb_python {
    template <typename ARG1, void FUN(ARG1)>
    static PyObject* Wrap1Void(PyObject *, PyObject *args) {
        if (PyTuple_Size(args) != 1) {
            PyErr_SetString(PyExc_ValueError,"Invalid argument count (need 1)");
            return nullptr;
        }
        auto arg1 = FromPy<ARG1>( PyTuple_GetItem(args, 0));
        FUN(arg1);
        return Py_None;
    }
    template <typename RET,  RET FUN(void)>
    static PyObject* Wrap0(PyObject *, PyObject *) {
        RET res = FUN();
        return ToPy<RET>(res);
    }


    template <typename RET, typename ARG1, RET FUN(ARG1)>
    static PyObject* Wrap1(PyObject *, PyObject *args) {
        if (PyTuple_Size(args) != 1) {
            PyErr_SetString(PyExc_ValueError,"Invalid argument count (need 1)");
            return nullptr;
        }
        auto arg1 = FromPy<ARG1>( PyTuple_GetItem(args, 0));
        RET res = FUN(arg1);
        return ToPy<RET>(res);
    }

    template <typename RET, typename ARG1, typename ARG2, RET FUN(ARG1, ARG2)>
    static PyObject* Wrap2(PyObject *, PyObject *args) {
        if (PyTuple_Size(args) != 2) {
            PyErr_SetString(PyExc_ValueError,"Invalid argument count (need 4)");
            return nullptr;
        }
        // TODO check for None etc?
        auto arg1 = FromPy<ARG1>( PyTuple_GetItem(args, 0));
        auto arg2 = FromPy<ARG2>( PyTuple_GetItem(args, 1));
        RET res = FUN(arg1, arg2);
        return ToPy<RET>(res);
    }

    template <typename RET, typename ARG1, typename ARG2, typename ARG3, RET FUN(ARG1, ARG2, ARG3)>
    static PyObject* Wrap3(PyObject *, PyObject *args) {
        if (PyTuple_Size(args) != 3) {
            PyErr_SetString(PyExc_ValueError,"Invalid argument count (need 4)");
            return nullptr;
        }
        // TODO check for None etc?
        auto arg1 = FromPy<ARG1>( PyTuple_GetItem(args, 0));
        auto arg2 = FromPy<ARG2>( PyTuple_GetItem(args, 1));
        auto arg3 = FromPy<ARG3>( PyTuple_GetItem(args, 2));
        RET res = FUN(arg1, arg2, arg3);
        return ToPy<RET>(res);
    }

    template <typename RET, typename ARG1, typename ARG2, typename ARG3, typename ARG4, RET FUN(ARG1, ARG2, ARG3, ARG4)>
    static PyObject* Wrap4(PyObject *, PyObject *args) {
        if (PyTuple_Size(args) != 4) {
            PyErr_SetString(PyExc_ValueError,"Invalid argument count (need 4)");
            return nullptr;
        }
        // TODO check for None etc?
        auto arg1 = FromPy<ARG1>( PyTuple_GetItem(args, 0));
        auto arg2 = FromPy<ARG2>( PyTuple_GetItem(args, 1));
        auto arg3 = FromPy<ARG3>( PyTuple_GetItem(args, 2));
        auto arg4 = FromPy<ARG4>( PyTuple_GetItem(args, 3));
        RET res = FUN(arg1, arg2, arg3, arg4);
        return ToPy<RET>(res);
    }

    template <typename RET, typename ARG1, typename ARG2, typename ARG3, typename ARG4, typename ARG5, RET FUN(ARG1, ARG2, ARG3, ARG4, ARG5)>
    static PyObject* Wrap5(PyObject *, PyObject *args) {
        if (PyTuple_Size(args) != 5) {
            PyErr_SetString(PyExc_ValueError,"Invalid argument count (need 4)");
            return nullptr;
        }
        // TODO check for None etc?
        auto arg1 = FromPy<ARG1>( PyTuple_GetItem(args, 0));
        auto arg2 = FromPy<ARG2>( PyTuple_GetItem(args, 1));
        auto arg3 = FromPy<ARG3>( PyTuple_GetItem(args, 2));
        auto arg4 = FromPy<ARG4>( PyTuple_GetItem(args, 3));
        auto arg5 = FromPy<ARG5>( PyTuple_GetItem(args, 3));

        RET res = FUN(arg1, arg2, arg3, arg4, arg5);
        return ToPy<RET>(res);
    }
}