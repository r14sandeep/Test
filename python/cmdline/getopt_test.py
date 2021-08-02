#!/usr/bin/python
import sys,getopt
def main(argv):
	inputfile=''
	outfile=''
	print argv
	try:
		opts,args=getopt.getopt(argv,"hi:o",["ifile=","ofile="])
	except getopt.GetoptError:
		print "getopt.py -i <inputfile> -o <outfile>"
	print 'args:',args
	print 'opts:',opts
	for opt,arg in opts:
		if opt == '-h':
			print "usage getopt.py -i <inputfile> -o <outfile>"
			sys.exit()
		elif opt in ("-i","--ifile"):
			inputfile=arg
		elif opt in ("-o","--ofile"):
			outfile=arg
	print "i/p file:",inputfile
	print "o/p file:",outfile
	return

if __name__=="__main__":
	main(sys.argv[1 : ])
