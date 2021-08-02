#!/bin/sh
echo -en "what is ur name [ `asdf` ]"
read myname
if [ -z "$myname" ]; then
	myname=`asdf`
fi
echo "name is $myname"
