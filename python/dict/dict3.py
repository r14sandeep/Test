#!/usr/bin/python
dict1={'name':'zara','age':7}
print "len is:",len(dict1)
dict1.clear()
print "len is:",len(dict1)
dict1={'name':'zara','age':7}
dict2=dict1.copy()
print "dict2:%s"%str(dict2)
seq=('name','age','class')
dict1=dict1.fromkeys(seq)
print "new dict:%s"%str(dict1)
dict1=dict1.fromkeys(seq,10)
print "new dict:%s"%str(dict1)




dict1={'name':'zara','age':7}
print "vallue %s"%dict1.get('age')
print "vallue %s"%dict1.get('class',"never")
print dict1


print "vallue %s"%dict1.has_key('age')
print "vallue %s"%dict1.has_key('class')

dict1={'name':'zara','age':7}
print "val %s"%dict1.setdefault('age',None)
print "val %s"%dict1.setdefault('class',None)
print dict1



dict1={'name':'zara','age':7}

dict2={'class':'ECE'}
dict1.update(dict2)
print dict1,dict2
print dict1.values()
