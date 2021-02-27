#ifndef FT_CONTAINER_HPP
# define FT_CONTAINER_HPP

# ifndef MY_COLORS
#  define MY_COLORS
#  define R_CYN "\e[46;30m"
#  define R_MGN "\e[45;30m"
#  define R_BLU "\e[44;30m"
#  define R_YLW "\e[43;30m"
#  define R_GRN "\e[42;30m"
#  define R_RED "\e[41;30m"
#  define CYN "\e[36m"
#  define MGN "\e[35m"
#  define BLU "\e[34m"
#  define YLW "\e[33m"
#  define GRN "\e[32m"
#  define RED "\e[31m"
#  define NC "\e[m"
# endif

# include "list.hpp"
# include "map.hpp"
# include "queue.hpp"
# include "stack.hpp"
# include "vector.hpp"
# include "alloc.hpp"

# include <iostream>
using std::string;
using std::cout;
using std::endl;


template< typename T >
void TITLE_RED(T str) {std::cout << R_RED << str << NC << std::endl;}
template< typename T >
void TITLE_BLU(T str) {std::cout << R_BLU << str << NC << std::endl;}
template< typename T >
void TITLE_GRN(T str) {std::cout << R_GRN << str << NC << std::endl;}
template< typename T >
void TITLE_MGN(T str) {std::cout << MGN << str << NC << std::endl;}

void test_list();
void test_vector();
void test_map();
void test_stack();
void test_queue();

#endif