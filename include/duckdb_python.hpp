#pragma once

#define Py_LIMITED_API 0x030A0000 // this needs to correspond with entry in setup.py
#include "Python.h"
#define DUCKDB_API_NO_DEPRECATED
#include "duckdb.h"