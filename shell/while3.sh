#!/bin/sh
while read f
do 
	#echo "line :$f"
	case $f in
		hello)	echo english ;;
		howdy)	echo am ;;
		*)	echo unknown: $f ;;
	
	esac
done < myfile
