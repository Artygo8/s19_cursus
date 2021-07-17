#!/bin/bash

######################
### PATHS ############
######################

if [ $# -eq 1 ]; then
    LIBFT=$1
else
    LIBFT=../libft
fi

######################
### COMPILER #########
######################

CFLAGS=-Werror -Wall -Wextra -g3 -fsanitize=address

######################
### COLORS ###########
######################

TITLE="\e[1;4m"
NC="\e[m"
BLU="\e[96m"
GRN="\e[32m"
RED="\e[31m"

######################
### TITLES ###########
######################

function title() {
    printf "$TITLE$* >$NC "
}

function testing() {
    title $*
    $* > /dev/null && printf "${GRN}Success$NC\n" || printf "${RED}Failure !$NC\n"
}

function part2_testing() {
    title ft_$*
    gcc tests/part2/test_$*.c $LIBFT/libft.a $CFLAGS -I $LIBFT
    ./a.out > /dev/null && printf "${GRN}Success$NC\n" || printf "${RED}Failure !$NC\n"
    rm -f a.out
}

function bonus_testing() {
    title ft_lst$*
    gcc tests/bonus/test_$*.c $LIBFT/libft.a $CFLAGS -I $LIBFT
    ./a.out > /dev/null && printf "${GRN}Success$NC\n" || printf "${RED}Failure !$NC\n"
    rm -f a.out
}

######################
### SCRIPT ###########
######################

clear

printf "\n${BLU}Make$NC\n\n"
testing make -C $LIBFT
testing make fclean -C $LIBFT
testing make bonus -C $LIBFT
testing make clean -C $LIBFT

printf "\n${BLU}Part 2$NC\n\n"
part2_testing itoa
part2_testing mapi
part2_testing split
part2_testing strjoin
part2_testing strtrim

printf "\n${BLU}Bonus$NC\n\n"
bonus_testing add_back
bonus_testing add_front
bonus_testing clear
bonus_testing delone
bonus_testing iter
bonus_testing last
bonus_testing map
bonus_testing new
bonus_testing size
