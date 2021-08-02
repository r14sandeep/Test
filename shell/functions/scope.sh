#!/bin/sh
myfun()
{
	echo "args are:$@"
	echo "arg cnt:$#"

	x=5
	y=$3
	echo "y=$y"
}
echo "script was called with $@"
x=1;y=10
echo "x is $x"
myfun 1 2 55
echo "x is $x"
echo "y is $y"
