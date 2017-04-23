#!/bin/zsh

printf "\033[34mTEST\033[0m\n";

diff =(./tests/test origin) =(./tests/test custom)

errors=$?

if [[ ${errors} == 0 ]]; then
	printf "\033[32mThere was no errors.\033[0m\n";
else
	printf "\033[31mThere was some error(s).\033[0m\n";
fi

exit ${errors}
