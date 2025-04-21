# only for development (for now?)
cmake_minimum_required(VERSION 3.30)

project(python_duckdb_neo)

include_directories(/opt/homebrew/opt/python@3.13/Frameworks/Python.framework/Versions/3.13/include/python3.13 include)

add_library(python_duckdb_neo_static src/native/init.cpp
        include/wrappers.hpp)