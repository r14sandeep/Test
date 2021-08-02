#!/usr/bin/python
import re
line="cats are smarter than dogs"
matchobj=re.match(r'dogs',line,re.M|re.I)
if matchobj:
	print "matched:",matchobj.group()
else:
	print "no match"
matchobj=re.search(r'Dogs',line,re.M|re.I)
if matchobj:
	print "matched:",matchobj.group()
#	print matchobj
else:
	print "no match"
match=re.match(r'dog','dog cat dog')
print match.group(0)


match=re.search(r'dog','dog cat dog')
print match.group(0)



match=re.findall(r'dog','dog cat dog')
print match
