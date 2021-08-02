#!/bin/bash
a[0]=1
a[1]=2
a[2]=3
echo "all indexes:${!a[*]}"
echo "all :${a[*]}"
echo "all:${a[@]}"
b=(apple mango grapes)
#b=()
echo All elements are
echo ${b[*]}
b[1]=12
echo "${b[1]}"
echo ${b[*]}

