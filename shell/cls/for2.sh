#!/bin/bash
dirs=0
files=0
g=`pwd`
echo $g
if [ -d $g/"temp"  ]
then
	echo "present:$g/"temp":"
fi

#for val in `ls`
#do
#	if [ -d $val ]
#	then
#		dirs=`expr $dirs + 1`
#	fi
#	if [ -f $val ]
#	then
#		files=`expr $files + 1`
#	fi	
#done	
#echo "dirs = $dirs"
#echo "files = $files"
