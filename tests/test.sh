#!/bin/bash

printf "\033[33mTEST\033[0m\n";

diff <(./tests/test origin) <(./tests/test custom)

errors=$?

if [[ ${errors} == 0 ]]; then
	printf "\033[32mThere was no errors.\033[0m\n";
else
	printf "\033[31mThere was some error(s).\033[0m\n";
fi

exit ${errors}
