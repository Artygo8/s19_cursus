/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 22:45:12 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/23 22:45:12 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

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

#define TITLE(str) std::cout << "\n" << R_CYN << str << NC << std::endl

template<typename T>
void	show(T stuff) { std::cout << stuff << std::endl; }

int main()
{

	{
		TITLE("Int");
		int array[] = {19, 42, 1337, 5};

		iter( array, 4, show );
	}
		
	{
		TITLE("string");
		std::string array[] = {"Merry Christmas", "Happy New year", "Hello", "Please", "AAAAAAAAAAAHHHH"};

		iter( array, 5, show );
	}

	return 0;
}

