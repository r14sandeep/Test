#!/bin/bash
for ((num=1;num<=10;num++))
do 
	echo $num
done
for num in 11 2 13 43 5
do 
	echo -n $num
	echo -n " "
done
echo
for num in {1..10..3}
do 
	echo $num
done
