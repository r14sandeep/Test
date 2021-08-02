#!/bin/sh
echo "enter your name"
read name
echo "hello $name"
echo "creating a file called $name"
touch "${name}_file"
touch $name
