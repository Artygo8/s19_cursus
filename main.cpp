/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 12:00:01 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/28 12:00:01 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.hpp"
#include "vector.hpp"
#include "map.hpp"
#include "stack.hpp"
#include "queue.hpp"

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

# define TITLE_RED(str) std::cout << R_RED << str << NC << std::endl
# define TITLE_BLU(str) std::cout << R_BLU << str << NC << std::endl
# define TITLE_GRN(str) std::cout << R_GRN << str << NC << std::endl

using std::string;
using std::cout;
using std::endl;


int main()
{
	TITLE_RED("__LIST_CONSTRUCTORS__");
	{
		TITLE_GRN("std");
		// constructors used in the same order as described above:
		std::list<int> first;                                // empty list of ints
		std::list<int> second (4,100);                       // four ints with value 100
		std::list<int> third (second.begin(),second.end());  // iterating through second
		std::list<int> fourth (third);                       // a copy of third

		// the iterator constructor can also be used to construct from arrays:
		int myints[] = {16,2,77,29};
		std::list<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

		std::cout << "The contents of fifth are: ";
		for (std::list<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
			std::cout << *it << ' ';
		std::cout << '\n';
	}

	{
		TITLE_GRN("ft");
		// constructors used in the same order as described above:
		ft::list<int> first;                                // empty list of ints
		ft::list<int> second (4, 100);                      // four ints with value 100
		ft::list<int> third (second.begin(),second.end());  // iterating through second
		ft::list<int> fourth (third);                       // a copy of third

		// the iterator constructor can also be used to construct from arrays:
		int myints[] = {16,2,77,29};
		ft::list<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

		std::cout << "The contents of fifth are: ";
		for (ft::list<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
			std::cout << *it << ' ';
		std::cout << '\n';
	}

	

	return 0;
}