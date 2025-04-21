{"duckdb_create_instance_cache", Wrap0<duckdb_instance_cache, duckdb_create_instance_cache>, METH_VARARGS, R"(Creates a new database instance cache.
The instance cache is necessary if a client/program (re)opens multiple databases to the same file within the same process.
Must be destroyed with 'duckdb_destroy_instance_cache'.

)"},
{"duckdb_get_or_create_from_cache", Wrap5<duckdb_state, duckdb_instance_cache, const char *, duckdb_database *, duckdb_config, char **, duckdb_get_or_create_from_cache>, METH_VARARGS, R"(Creates a new database instance in the instance cache, or retrieves an existing database instance.
Must be closed with 'duckdb_close'.

)"},
{"duckdb_destroy_instance_cache", Wrap1Void<duckdb_instance_cache *, duckdb_destroy_instance_cache>, METH_VARARGS, R"(Destroys an existing database instance cache and de-allocates its memory.

)"},
{"duckdb_open", Wrap2<duckdb_state, const char *, duckdb_database *, duckdb_open>, METH_VARARGS, R"(Creates a new database or opens an existing database file stored at the given path.
If no path is given a new in-memory database is created instead.
The database must be closed with 'duckdb_close'.

)"},
{"duckdb_open_ext", Wrap4<duckdb_state, const char *, duckdb_database *, duckdb_config, char **, duckdb_open_ext>, METH_VARARGS, R"(Extended version of duckdb_open. Creates a new database or opens an existing database file stored at the given path.
The database must be closed with 'duckdb_close'.

)"},
{"duckdb_close", Wrap1Void<duckdb_database *, duckdb_close>, METH_VARARGS, R"(Closes the specified database and de-allocates all memory allocated for that database.
This should be called after you are done with any database allocated through `duckdb_open` or `duckdb_open_ext`.
Note that failing to call `duckdb_close` (in case of e.g. a program crash) will not cause data corruption.
Still, it is recommended to always correctly close a database object after you are done with it.

)"},
{"duckdb_connect", Wrap2<duckdb_state, duckdb_database, duckdb_connection *, duckdb_connect>, METH_VARARGS, R"(Opens a connection to a database. Connections are required to query the database, and store transactional state
associated with the connection.
The instantiated connection should be closed using 'duckdb_disconnect'.

)"},
{"duckdb_interrupt", Wrap1Void<duckdb_connection, duckdb_interrupt>, METH_VARARGS, R"(Interrupt running query

)"},
{"duckdb_query_progress", Wrap1<duckdb_query_progress_type, duckdb_connection, duckdb_query_progress>, METH_VARARGS, R"(Get progress of the running query

)"},
{"duckdb_disconnect", Wrap1Void<duckdb_connection *, duckdb_disconnect>, METH_VARARGS, R"(Closes the specified connection and de-allocates all memory allocated for that connection.

)"},
{"duckdb_library_version", Wrap0<const char *, duckdb_library_version>, METH_VARARGS, R"(Returns the version of the linked DuckDB, with a version postfix for dev versions

Usually used for developing C extensions that must return this for a compatibility check.
)"},
