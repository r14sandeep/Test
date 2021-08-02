#!/bin/bash
hello()
{
#	echo "hello world"
	echo "hello world,$1 $2 $3"
	return `expr $1 + $2`
}
hello 
hello 1 2
echo hello is $? 
