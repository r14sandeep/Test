#!/usr/bin/python
f=open("foo.txt","rw+")
string="this is 6th line\n"
f.seek(0,2)
print f.tell()
f.write(string)
f.seek(0,0)
for line in f:
#	print f.tell()
	print line #prints each line
print f.tell()
f.close()
#f=open("foo.txt","a")
#string="this is 7th line\n"
#f.write(string)

#f.close()
