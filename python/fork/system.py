#!/usr/bin/python
import os
print os.system('echo $HOME>outfile')
f=open("outfile","r")
print f.read()



stream=os.popen('echo $HOME')
print stream.read()
print os.system('ls')
