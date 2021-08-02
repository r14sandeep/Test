#!/usr/bin/python
from collections import deque

d=deque([1,2,3,4])
print d
d.append(10)
print d
d.popleft()
print d
