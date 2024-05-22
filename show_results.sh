#!/bin/bash
while true
do
	n=$(sed -n -e '$=' nohup.out)
	n=$(expr $n - 1)
	sed -n -e "${n}"',$p' nohup.out
	sleep 1
done
