#!/bin/bash
echo "enter v1"
read v1
if [ $v1 -lt 10 ]
then 
	echo "lt"
elif [ $v1 -gt 10 ]
then
	echo "gt"
else
	echo "eq"
fi
