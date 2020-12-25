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

#include "Array.hpp"

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

#define TITLE_CYN(str) std::cout << "\n" << R_CYN << str << NC << std::endl
#define TITLE_RED(str) std::cout << "\n" << R_RED << str << NC << std::endl

template<typename T>
void	show(T stuff) { std::cout << stuff << std::endl; }


int main()
{

	TITLE_RED("=== BASICS ===");
	TITLE_CYN("create array of 3 and access to its 100 first elements.");
	try
	{
		::Array<int> a(3);

		for (int i = 0; i < 100; i++)
			std::cout << a[i] << std::endl;
		
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	TITLE_CYN("create array of -3");
	try
	{
		::Array<int> a(-3);		
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	TITLE_CYN("create array of 0 and access to the element at position 0.");
	try
	{
		::Array<int> a(0);
		std::cout << a[0] << std::endl;

	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	TITLE_RED("=== ASSIGNATION ===");
	TITLE_CYN("create array of 3, init it, copy it, modify the first and print both.");
	try
	{
		::Array<std::string> a(3);

		for (int i = 0; i < 3; i++)
			a[i] = "coucou";

		::Array<std::string> b = a;

		for (int i = 0; i < 3; i++)
			a[i] = "bojour";

		for (int i = 0; i < 3; i++)
			std::cout << a[i] << std::endl;

		for (int i = 0; i < 3; i++)
			std::cout << b[i] << std::endl;
		
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	TITLE_RED("=== COPY CONSTRUCTOR ===");
	TITLE_CYN("create array of 3, init it, copy it, modify the first and print both.");
	try
	{
		::Array<std::string> a(3);

		for (int i = 0; i < 3; i++)
			a[i] = "coucou";

		::Array<std::string> b = a;

		for (int i = 0; i < 3; i++)
			a[i] = "bojour";

		for (int i = 0; i < 3; i++)
			std::cout << a[i] << std::endl;

		for (int i = 0; i < 3; i++)
			std::cout << b[i] << std::endl;
		
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}

