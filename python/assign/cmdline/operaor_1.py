#!/usr/bin/python
import sys
if sys.argv[2]=='+':
	print int(sys.argv[1])+int(sys.argv[3])
elif sys.argv[2]=='-':
	print int(sys.argv[1])-int(sys.argv[3])
elif sys.argv[2]=='*':
	print "******"
	print int(sys.argv[1])*int(sys.argv[3])
elif sys.argv[2]=='/':
	print int(sys.argv[1])/int(sys.argv[3])
elif sys.argv[2]=='%':
	print int(sys.argv[1])%int(sys.argv[3])
#print int(sys.argv[1])*int(sys.argv[3])
	
