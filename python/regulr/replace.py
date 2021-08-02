#!/usr/bin/python
import re
phone = '123-66-5as65-54 #this is number'
num=re.sub(r'#.*$','',phone)
print num
#print phone
num =re.sub(r'\D','',phone)
print num
