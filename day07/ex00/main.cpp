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

#include "whatever.hpp"

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

int main()
{
	{
		TITLE("Floats");
		float a = 76.5;
		float b = 74.0;

		std::cout << "a is equal to " << a << std::endl;
		std::cout << "b is equal to " << b << std::endl;

		std::cout << "== SWAP ==" << std::endl;
		::swap(a, b);

		std::cout << "a is equal to " << a << std::endl;
		std::cout << "b is equal to " << b << std::endl;

		std::cout << "== COMPARE ==" << std::endl;

		std::cout << "implicit ::max of a and b: " << ::max( a, b ) << std::endl;
		std::cout << "explicit (float) ::max of a and b: " << ::max<float>( a, b ) << std::endl;
		std::cout << "explicit (int) ::max of a and b: " << ::max<int>( a, b ) << std::endl;
		std::cout << "explicit (char) ::max of a and b: " << ::max<char>( a, b ) << std::endl;

		std::cout << "implicit ::min of a and b: " << ::min( a, b ) << std::endl;
		std::cout << "explicit (float) ::min of a and b: " << ::min<float>( a, b ) << std::endl;
		std::cout << "explicit (int) ::min of a and b: " << ::min<int>( a, b ) << std::endl;
		std::cout << "explicit (char) ::min of a and b: " << ::min<char>( a, b ) << std::endl;
	}

	{
		TITLE("Ints");
		int a = 11;
		int b = -5;

		std::cout << "a is equal to " << a << std::endl;
		std::cout << "b is equal to " << b << std::endl;

		std::cout << "== SWAP ==" << std::endl;
		::swap(a, b);

		std::cout << "a is equal to " << a << std::endl;
		std::cout << "b is equal to " << b << std::endl;

		std::cout << "== COMPARE ==" << std::endl;

		std::cout << "implicit ::max of a and b: " << ::max( a, b ) << std::endl;
		std::cout << "explicit ::max of a and b: " << ::max<float>( a, b ) << std::endl;

		std::cout << "implicit ::min of a and b: " << ::min( a, b ) << std::endl;
		std::cout << "explicit ::min of a and b: " << ::min<float>( a, b ) << std::endl;
	}

	{
		TITLE("Chars");
		char a = 'a';
		char b = 'b';

		std::cout << "a is equal to " << a << std::endl;
		std::cout << "b is equal to " << b << std::endl;

		std::cout << "== SWAP ==" << std::endl;
		::swap(a, b);

		std::cout << "a is equal to " << a << std::endl;
		std::cout << "b is equal to " << b << std::endl;

		std::cout << "== COMPARE ==" << std::endl;

		std::cout << "implicit ::max of a and b: " << ::max( a, b ) << std::endl;
		std::cout << "explicit ::max of a and b: " << ::max<char>( a, b ) << std::endl;
		std::cout << "explicit (to int) ::max of a and b: " << ::max<int>( a, b ) << std::endl;

		std::cout << "implicit ::min of a and b: " << ::min( a, b ) << std::endl;
		std::cout << "explicit ::min of a and b: " << ::min<char>( a, b ) << std::endl;
		std::cout << "explicit (to int) ::min of a and b: " << ::min<int>( a, b ) << std::endl;
	}

	{
		TITLE("SUBJECT MAIN");
		
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}

	return 0;
}
