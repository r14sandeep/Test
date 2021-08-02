#!/usr/bin/python
f=open("foo.txt","r")
'''for index in range(6):
	#line=f.next()
	line=f.readline()#reads complet line
	#line=f.readline(15)#reads 15 bytes in a line
	
	print "line no:%d-%s"%(index+1,line)
'''
line=f.readline()
while line!=None:
#	print "in"
	print line
	line=f.readline()
f.seek(0,0)
#print f.readlines()#reads all line in the form of list
#print f.readlines(5)#reads all line in the form of list
print f.readline()

#for line in f:
#	print line
f.close()
