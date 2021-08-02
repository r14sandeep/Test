#!/bin/sh
string="hi"
while [ "$string" != "exit" ]
do 
	echo "enter a string"
	read string
	echo "u hv entered $string"
done
