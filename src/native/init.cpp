#define Py_LIMITED_API 0x030A0000 // this needs to correspond with entry in pyproject.toml
#include "Python.h"
#define DUCKDB_API_NO_DEPRECATED
#include "duckdb.h"

static PyObject *
duckdb_open_wrapper(PyObject *self, PyObject *args)
{
    duckdb_database db;
    auto x = duckdb_open(nullptr, &db);
    return PyLong_FromLong(42);
}

static PyMethodDef duckdb_methods[] = {
    {"duckdb_open_wrapper",  duckdb_open_wrapper, METH_VARARGS,
     "TODO"},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

static struct PyModuleDef duckdb_module = {
    PyModuleDef_HEAD_INIT,
    "duckdb.native",   /* name of module */
    NULL, /* module documentation, may be NULL */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    duckdb_methods
};

extern "C" {
	PyMODINIT_FUNC PyInit_native(void)
	{
	    return PyModule_Create(&duckdb_module);
	}
}