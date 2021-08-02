#!/bin/bash
arr=()
echo "enter values into array:"
for((i=0;i<10;i++))
do
	read arr[$i]
	
done
for((i=0;i<10;i++))
do
	echo ${arr[$i]}
done
