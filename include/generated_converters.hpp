
#pragma once
#include "duckdb_python.hpp"
#include "converters.hpp"
#include "pointer_wrappers.hpp"

namespace duckdb_python {

template <> duckdb_config * FromPy(PyObject* self) {
    return Unwrap<duckdb_config>(self);
}
		
template <> duckdb_config FromPy(PyObject* self) {
    return *Unwrap<duckdb_config>(self);
}
		
template <> duckdb_instance_cache FromPy(PyObject* self) {
    return *Unwrap<duckdb_instance_cache>(self);
}
		
template <> duckdb_database * FromPy(PyObject* self) {
    return Unwrap<duckdb_database>(self);
}
		
template <> duckdb_instance_cache * FromPy(PyObject* self) {
    return Unwrap<duckdb_instance_cache>(self);
}
		
template <> duckdb_database FromPy(PyObject* self) {
    return *Unwrap<duckdb_database>(self);
}
		
template <> duckdb_connection * FromPy(PyObject* self) {
    return Unwrap<duckdb_connection>(self);
}
		
template <> duckdb_connection FromPy(PyObject* self) {
    return *Unwrap<duckdb_connection>(self);
}
		
template <> PyObject* ToPy(duckdb_query_progress_type self) {
    return nullptr; // TODO
}
		
}
