#!/bin/bash
v1=22
v2=2
echo [ $v1 -gt 30 -o $v2 -eq 12 ]
echo $?
echo "[$v1 -gt 30 -a $v2 -eq 12 ]"
echo $?
