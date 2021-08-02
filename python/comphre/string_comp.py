#!/usr/bin/python
words='the great indian army'.split()#stores the words in list form
print words
stuf=[[word.upper(),word.lower(),len(word)]for word in words]
print stuf
for word in stuf:
	print word
