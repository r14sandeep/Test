import os, re
for (root, d, files) in os.walk('./'):
	for f in files:
		if re.search(r"\.py$", f):
			
			print f
			
		
