#!/usr/bin/env python
# -*- coding: utf-8 -*-

import os
import glob
import zipfile
import tempfile
import setuptools
import urllib.request

# TODO figure out platform
libduckdb_url = 'https://github.com/duckdb/duckdb/releases/download/v1.2.2/static-libs-osx-arm64.zip'

temp_zip_file = tempfile.mktemp()
#temp_zip_file = 'static-libs-osx-arm64.zip'
urllib.request.urlretrieve(libduckdb_url, temp_zip_file)
zf = zipfile.ZipFile(temp_zip_file, "r")
temp_dir = tempfile.TemporaryDirectory()
zf.extractall(temp_dir.name)
zf.close()
duckdb_static_libs = [os.path.join(temp_dir.name,  x) for x in glob.glob("*.a", root_dir=temp_dir.name)]

setuptools.setup(
    ext_modules=[setuptools.Extension(
        'duckdb.native',
        include_dirs=[temp_dir.name, "include"],
        sources=['src/native/init.cpp'],
        extra_compile_args=['-std=c++11'],
        extra_link_args=[], # WINDOWS?!
        extra_objects=duckdb_static_libs,
        language='c++',
        define_macros=[],
        py_limited_api = True
    )],
    options={'bdist_wheel': {'py_limited_api': 'cp310'}},
)