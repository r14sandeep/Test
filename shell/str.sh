#!/bin/bash
read str
#echo ${str[0]}
l=${#str}
for((i=0;i<l;i++))
do
	echo ${str:$i:1}
	echo $i
done
