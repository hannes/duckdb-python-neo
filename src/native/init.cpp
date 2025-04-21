#include "duckdb_python.hpp"
#include "pointer_wrappers.hpp"
#include "converters.hpp"
#include "generated_converters.hpp"
#include "method_wrappers.hpp"



using namespace duckdb_python;


static PyMethodDef duckdb_methods[] = {
    {"duckdb_database_alloc", Alloc<duckdb_database> , METH_VARARGS,
     "TODO"},

{"duckdb_database_free", Free<duckdb_database> , METH_VARARGS,
"TODO"},

{"duckdb_config_alloc", Alloc<duckdb_config> , METH_VARARGS,
 "Allocate config object"},

{"duckdb_config_free", Free<duckdb_config> , METH_VARARGS,
"Free config object"},

{"duckdb_outstring_alloc", Alloc<char**> , METH_VARARGS,
 "Allocate outstring object"},

{"duckdb_outstring_free", Free<char**> , METH_VARARGS,
"Free outstring object"},


    // TODO investigate METH_FASTCALL usage
{"duckdb_open_ext", Wrap4<duckdb_state, const char*, duckdb_database*, duckdb_config, char**, duckdb_open_ext> , METH_VARARGS,
"TODO"},

{"duckdb_close", Wrap1Void<duckdb_database*, duckdb_close> , METH_VARARGS,
"TODO"},

#include "configuration.cpp"
#include "open_connect.cpp"

    {NULL, NULL, 0, NULL}        /* Sentinel */
};

static struct PyModuleDef duckdb_module = {
    PyModuleDef_HEAD_INIT,
    "duckdb.native",   /* name of module */
    "Native Python bindings for DuckDB", /* module documentation, may be NULL */
    0,   /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    duckdb_methods
};

extern "C" {
	PyMODINIT_FUNC PyInit_native(void) {
	    return PyModule_Create(&duckdb_module);
	}
}