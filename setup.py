#!/usr/bin/env python
# -*- coding: utf-8 -*-

import zipfile
import urllib.request
import os
import tempfile

from setuptools import setup, Extension

libduckdb_url = 'https://github.com/duckdb/duckdb/releases/download/v1.2.2/static-libs-osx-arm64.zip'
temp_zip_file = tempfile.mktemp()

urllib.request.urlretrieve(libduckdb_url, temp_zip_file)


temp_dir = tempfile.TemporaryDirectory()

zf = zipfile.ZipFile(temp_zip_file, "r")
zf.extractall(temp_dir.name)


setup(
    ext_modules=[Extension(
        'duckdb.native',
        include_dirs=[temp_dir.name],
        sources=['src/native/init.cpp'],
        extra_compile_args=[],
        extra_link_args=[],
        libraries=[],
        library_dirs=[],
        language='c++',
        define_macros=[],
        py_limited_api = True
    )],
    options={'bdist_wheel': {'py_limited_api': 'cp310'}},

)