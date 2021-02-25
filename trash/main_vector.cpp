/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 12:00:01 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/28 12:00:01 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>

#ifndef MY_COLORS
# define MY_COLORS
# define R_CYN "\e[46;30m"
# define R_MGN "\e[45;30m"
# define R_BLU "\e[44;30m"
# define R_YLW "\e[43;30m"
# define R_GRN "\e[42;30m"
# define R_RED "\e[41;30m"
# define CYN "\e[36m"
# define MGN "\e[35m"
# define BLU "\e[34m"
# define YLW "\e[33m"
# define GRN "\e[32m"
# define RED "\e[31m"
# define NC "\e[m"
#endif

using std::string;
using std::cout;
using std::endl;

template< typename T >
void TITLE_RED(T str) {std::cout << R_RED << str << NC << std::endl;}
template< typename T >
void TITLE_BLU(T str) {std::cout << R_BLU << str << NC << std::endl;}
template< typename T >
void TITLE_GRN(T str) {std::cout << R_GRN << str << NC << std::endl;}

//  _              _     
// | |            | |    
// | |_ ___   ___ | |___ 
// | __/ _ \ / _ \| / __|
// | || (_) | (_) | \__ \\
//  \__\___/ \___/|_|___/
//                       


//                  _       
//                 (_)      
//  _ __ ___   __ _ _ _ __  
// | '_ ` _ \ / _` | | '_ | 
// | | | | | | (_| | | | | |
// |_| |_| |_|\__,_|_|_| |_|
//                          

int main()
{
	TITLE_RED("__VECTOR_CONSTRUCTORS__");

	TITLE_GRN("std");
	{
		// constructors used in the same order as described above:
		std::vector<int> first;                                // empty vector of ints
		std::vector<int> second (4,100);                       // four ints with value 100
		std::vector<int> third (second.begin(),second.end());  // iterating through second
		std::vector<int> fourth (third);                       // a copy of third

		// the iterator constructor can also be used to construct from arrays:
		int myints[] = {16,2,77,29};
		std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

		std::cout << "The contents of fifth are:";
		for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	TITLE_GRN("ft");
	{
		// constructors used in the same order as described above:
		ft::vector<int> first;                                // empty vector of ints
		ft::vector<int> second (4,100);                       // four ints with value 100
		ft::vector<int> third (second.begin(),second.end());  // iterating through second
		ft::vector<int> fourth (third);                       // a copy of third
		
		// the iterator constructor can also be used to construct from arrays:
		int myints[] = {16,2,77,29};
		ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
		
		std::cout << "The contents of fifth are:";
		for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}

	return 0;
	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}

	TITLE_RED("");

	TITLE_GRN("std");
	{

	}
	TITLE_GRN("ft");
	{

	}


	return 0;
}