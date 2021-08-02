#!/bin/bash
#sudo apt-get install gawk wget git-core diffstat unzip texinfo gcc-multilib build-essential chrpath
echo "enter manchine name:"
read machine
#echo $machine
echo "enter kernel version:"
read kernel
#ls
#sudo su
if [ $machine == "dragonboard-410c" ]
then
	en="dragon-build"
	dir="~/Yocto/dragon/sources"
	#mkdir -p ~/dragon/sources
	mkdir -p $dir
	cd $dir
	git clone -b rocko git://git.yoctoproject.org/poky.git
#	git clone -b rocko git://git.openembedded.org/meta-openembedded
#	git clone -b rocko https://github.com/ndechesne/meta-qcom.git
	cd ~/dragon/
fi
source sources/poky/oe-init-build-env $en
#echo 'MACHINE = "dragonboard-410c"' >> /conf/local.conf
#echo 'PREFERRED_VERSION_linux-linaro-qcom = "4.9"'>> ./conf/local.conf
#echo 'DISTRO_FEATURES_remove = "x11 wayland"' >> conf/local.conf
	

