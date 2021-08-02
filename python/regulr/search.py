import re
cont="abc dog cat dog dog"
#cont='voatarytech 123-45,abc,xyz:555-4545 hyd 500001'
mat=re.search(r'(\w+),(\w+):(\S+)',cont)
#mat=re.search(r'\w+,\w+:\S+',cont)
mat=re.findall(r'dog',cont)
print mat
#print mat.group(1)
#print mat.group(2)
#print mat.group(3)
