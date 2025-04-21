{"duckdb_create_config", Wrap1<duckdb_state, duckdb_config *, duckdb_create_config>, METH_VARARGS, R"(Initializes an empty configuration object that can be used to provide start-up options for the DuckDB instance
through `duckdb_open_ext`.
The duckdb_config must be destroyed using 'duckdb_destroy_config'

This will always succeed unless there is a malloc failure.

Note that `duckdb_destroy_config` should always be called on the resulting config, even if the function returns
`DuckDBError`.

)"},
{"duckdb_config_count", Wrap0<size_t, duckdb_config_count>, METH_VARARGS, R"(This returns the total amount of configuration options available for usage with `duckdb_get_config_flag`.

This should not be called in a loop as it internally loops over all the options.

)"},
{"duckdb_get_config_flag", Wrap3<duckdb_state, size_t, const char **, const char **, duckdb_get_config_flag>, METH_VARARGS, R"(Obtains a human-readable name and description of a specific configuration option. This can be used to e.g.
display configuration options. This will succeed unless `index` is out of range (i.e. `>= duckdb_config_count`).

The result name or description MUST NOT be freed.

)"},
{"duckdb_set_config", Wrap3<duckdb_state, duckdb_config, const char *, const char *, duckdb_set_config>, METH_VARARGS, R"(Sets the specified option for the specified configuration. The configuration option is indicated by name.
To obtain a list of config options, see `duckdb_get_config_flag`.

In the source code, configuration options are defined in `config.cpp`.

This can fail if either the name is invalid, or if the value provided for the option is invalid.

)"},
{"duckdb_destroy_config", Wrap1Void<duckdb_config *, duckdb_destroy_config>, METH_VARARGS, R"(Destroys the specified configuration object and de-allocates all memory allocated for the object.

)"},
