import os
filename = raw_input("File Namde: ")
for i,j,k in os.walk('./Desktop'):
	for val in k:
		if '.' in val:
			f = open(val, "r")
			if filename in f.read():
				print i, val
			f.close()
