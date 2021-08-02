#!/bin/bash
getopts abcl opt
case "$opt" in
	a) echo "entered a";;
	b) echo "entered b";;
	c) echo "entered c";;
	l) echo "entered d";;	
	*)echo "invalid"
esac

