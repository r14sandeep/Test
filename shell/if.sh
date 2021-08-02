#!/bin/sh
#a=5
a="as"
echo "enter a num"
read b
#if [ "$a" -eq "$b" ]
if [ "$a" = "$b" ]
then
	echo "equal"
else
	echo "not equal"
fi
