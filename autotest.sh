#!/bin/bash

our=`pwd`/hotrace
other=~/Downloads/hotrace

tests=(~/Downloads/resources/*.htr)

for t in ${tests[*]}; do
	res_our=$(mktemp)
	res_other=$(mktemp)

	echo -e "================ \033[0;33m$t\033[0m"
	echo -en "\033[0;32m=> Our: \033[0m"
	time $our < $t > $res_our
	echo -en "\033[0;31m=> Other: \033[0m"
	time $other < $t > $res_other

	diff $res_our $res_other > /dev/null \
		&& (echo -e "================ \033[0;32mOK\033[0m" && rm -f $res_our $res_other) \
		|| (echo -e "================ \033[0;31mDifferent\033[0m" && echo "vim -d $res_our $res_other")

	echo
done
