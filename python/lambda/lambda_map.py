#!/usr/bin/pytohn
def prefix(word):
	res='--'+word
	return res
variable_names=['m','func','y0']
options=[]
"""var_names_len=len(variable_names)
for index in range(var_names_len):
	item=variable_names[index]
	new_item=prefix(item)
	options.append(new_item)
print variable_names
print options"""



options=map(prefix,variable_names)
print options

#options=map(lambda word: '--' + word,variable_names)
#print options
