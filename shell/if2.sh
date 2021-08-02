#!/bin/sh
x=1
if [ "$x" -lt "2" ]; then
	echo "$x is less than 2"
fi
x=5
if [ "$x" -gt "2" ]; then
	echo "$x is greater than 2"
fi
#y=0
if [ -n "$y" ]; then
	echo "$x is non zero length"
fi
x="file"
if [ -f "$x" ]; then
	echo "$x is path of file"
fi

if [ -x "$x" ]; then
	echo "$x is path of exe"
fi
x="file"
if [ "$x" -nt "myfile" ]; then
	echo "$x is newer than myfile"
fi
x="script.sh"
if [ "$x" -ot "myfile" ]; then
	echo "$x is older than myfile"
fi
