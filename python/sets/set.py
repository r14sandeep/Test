#!/usr/bin/python
charset=set("a pytohn tutorial")
dtype=type(charset)
print "type:",dtype,charset
listset=set(['java','python','perl'])
print listset

cities={'paris','hyd','delhi','mumbai'}
cities=set(cities)
print cities


cities=set((('paris','hyd'),('delhi','mumbai')))
print cities
#cities=set((['paris','hyd'],['delhi','mumbai']))#error
#print cities
