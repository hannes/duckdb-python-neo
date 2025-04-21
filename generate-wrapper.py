import json

in_prefix = '/Users/hannes/source/duckdb/src/include/duckdb/main/capi/header_generation/functions/'
files = ['configuration.json', 'open_connect.json']
out_prefix = 'src/native/'

param_types = {}
return_types = {}

for f in files:
	in_file = open(f'{in_prefix}{f}', 'rb')
	s = json.loads(in_file.read())

	in_file.close()

	out_file = open(f'{out_prefix}{f.replace('.json', '.cpp')}', 'wb')

	for e in s['entries']:
		print(e['name'])

		template_params = []
		voidstr = 'Void'

		if e['return_type'] != 'void':
			voidstr = ''
			template_params.append(e['return_type'])
			if e['return_type'].startswith('duckdb_'):
				return_types[e['return_type']] = 1

		for p in e['params']:
			if p['type'].startswith('duckdb_'):
				param_types[p['type']] = 1
			template_params.append(p['type'])

		template_params.append(e['name'])
		wrap = f'Wrap{len(e['params'])}{voidstr}<{', '.join(template_params)}>'
		out_file.write(f'{{"{e['name']}", {wrap}, METH_VARARGS, R"({e['comment']['description']})"}},\n'.encode('utf8'))


# special cases
excludes = ['duckdb_state']

param_types_list = [x for x in param_types.keys()]
return_types_list = [x for x in return_types.keys()]

converters_file = open(f'include/generated_converters.hpp', 'wb')

param_types_list.sort()

converters_file.write('''
#pragma once
#include "duckdb_python.hpp"
#include "converters.hpp"
#include "pointer_wrappers.hpp"

namespace duckdb_python {
'''.encode('utf8'))

print(return_types_list)

for type in param_types:
	if type in excludes:
		continue
	if (type.endswith('*')):
		converters_file.write(f'''
template <> {type} FromPy(PyObject* self) {{
    return Unwrap<{type.replace(' *', '')}>(self);
}}
		'''.encode('utf8'))
	else:
		converters_file.write(f'''
template <> {type} FromPy(PyObject* self) {{
    return *Unwrap<{type}>(self);
}}
		'''.encode('utf8'))

for type in return_types:
	print(type)

	if type in excludes  or type == 'duckdb_instance_cache': # orrr
		continue
	if (type.endswith('*')):
		converters_file.write(f'''
template <> PyObject* ToPy({type} self) {{
    return nullptr; // TODO
}}
		'''.encode('utf8'))
	else:
		converters_file.write(f'''
template <> PyObject* ToPy({type} self) {{
    return nullptr; // TODO
}}
		'''.encode('utf8'))



converters_file.write('''
}
'''.encode('utf8'))
