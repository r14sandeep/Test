import os, sys

#print "The child will write text to a pipe and "
#print "the parent will read the text written by child..."

# file descriptors r, w for reading and writing
re, wr = os.pipe() 
v=3
processid = os.fork()
if processid:
    # This is the parent process 
    # Closes file descriptor w
	#v+=10
	#print "v:",v
	os.close(wr)
	r = os.fdopen(re)
	print "Parent reading"
	str = r.read()
	print "text =", str   
	sys.exit(0)
else:
    # This is the child process
	v+=10
	os.close(re)
	w = os.fdopen(wr, 'w')
	print "Child writing"
	#w.write("Text written by child...")
	w.write(str(v))
	w.close()
	print "Child closing"
	sys.exit(0)
