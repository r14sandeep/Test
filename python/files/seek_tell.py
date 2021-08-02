#!/usr/bin/python
f=open("seek.txt","r+")
#f.write("python is a great language\nyaeh its great\n")
#print "pos:",f.tell()
#f.seek(0,0)
line=f.read(12)
print "str:",line
pos = f.tell()
print "pos:",pos
f.seek(4,0)
line=f.read(10)
print "str:",line
pos=f.tell()
print "pos:",pos
f.seek(-14,2)
line=f.read(10)
print "str:",line
pos=f.tell()
print "pos:",pos

