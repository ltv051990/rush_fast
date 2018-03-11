#!/bin/bash

our=~/Desktop/tlutsyk/hotrace
other=~/Desktop/tlutsyk/other/hotrace

tests=(~/Downloads/resources/*.htr)

for t in ${tests[*]}; do
	res_our=$(mktemp)
	res_other=$(mktemp)
	diff=$(mktemp)

	echo -e "================ \033[0;33m$t\033[0m"
	echo -en "\033[0;32m=> Our: \033[0m"
	time $our < $t > $res_our
	echo -en "\033[0;31m=> Other: \033[0m"
	time $other < $t > $res_other

	diff $res_our $res_other > $diff \
		&& echo -e "================ \033[0;32mOK\033[0m" && rm -f $diff \
		|| echo -e "================ \033[0;31mDifferent \033[0m(see \033[0;36m$diff\033[0m)"
	rm -f $res_our $res_other

	echo
done
