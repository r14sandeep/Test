#!/usr/bin/python
cities=set(['hyd','delhi'])
print cities
cities.add('bombay')
print cities


cities=frozenset(['hyd','delhi'])
#cities.add('bombay')
print cities
cities={'hyd','delhi'}
print cities,type(cities)
