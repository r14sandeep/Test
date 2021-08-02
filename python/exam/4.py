#!/usr/bin/python
import sys,getopt
def main(argv):
	inputfile=''
	outfile=''
	try:
		opts,args=getopt.getopt(argv,'i:o',["ifile=","ofile="])
	except getopt.GetoptError:
		print "getopt.py -i <inputfile> -o <outfile>"
	for opt,arg in opts:
		if opt in ('-i','--ifile'):
			inputfile=arg
		
		elif opt in ('-o','--ofile'):
			outfile=arg
		outfile=argv[3]
	fr=open(inputfile,"r")
	buf=fr.readline()
	fw=open(outfile,"w")
	res=0
	while buf!='':
		res+=int(buf)	
		buf=fr.readline()
	fw.write(str(res))
	fr.close()
	fw.close()
			
if __name__=="__main__":
	main(sys.argv[1:])	
