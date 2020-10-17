#!/bin/bash

######################
### PATHS ############
######################

LIBFT=../libft
ORIGIN=$(echo `pwd`)

######################
### COMPILER #########
######################

CFLAGS=-Werror -Wall -Wextra -g3 -fsanitize=address

######################
### COLORS ###########
######################

RED="\033[1;31m"
COLOR="\033[3;37m"
NOCOLOR="\033[3;36m"

######################
### TITLES ###########
######################

FRAME="++++++++++++++++++++++++++\n"
T_LCLEAN="${NOCOLOR}${FRAME}++ Cleaning Library ++++++\n${FRAME}${COLOR}"
T_MBONUS="${NOCOLOR}${FRAME}++ Making Bonuses ++++++++\n${FRAME}${COLOR}"
T_OCLEAN="${NOCOLOR}${FRAME}++ Cleaning -.o ++++++++++\n${FRAME}${COLOR}"
T_TEST1="${NOCOLOR}${FRAME}++ PART 2 ++++++++++++++++\n${FRAME}${COLOR}"
T_TEST2="${NOCOLOR}${FRAME}++ BONUS +++++++++++++++++\n${FRAME}${COLOR}"

######################
### SCRIPT ###########
######################

clear
cd ${LIBFT}\
&& echo -e ${T_LCLEAN}; make fclean\
&& echo -e ${T_MBONUS}; make bonus\
&& echo -e ${T_OCLEAN}; make clean\
&& cd ${ORIGIN}\
&& echo -e ${T_TEST1}; gcc test_part2.c ${LIBFT}/libft.a ${CFLAGS}; ./a.out\
&& echo -e ${T_TEST2}; gcc test_bonus.c ${LIBFT}/libft.a ${CFLAGS}; ./a.out
echo -e "\033[m"
rm a.out
