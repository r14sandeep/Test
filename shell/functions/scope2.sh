#!/bin/sh
fun()
{
	echo "\$1 is $1"
	echo "\$2 is $2"
	a="gudbie"
}
a="hello"
b="world"
fun $a $b
echo "a is $a"
echo "b is $b"

