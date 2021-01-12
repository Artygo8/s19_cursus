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
#define P(X) std::cout << X << std::endl;

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

// // ARTAINMO MAIN TESTING CONST

// template<typename T>
// void show(Array<T> const &obj, int size)
// {
// 	if (size == 0)
// 	{
// 		std::cout << "empty array" << std::endl;
// 		return ;
// 	}
// 	for (int i = 0; i < size; i++)
// 		std::cout << obj[i];
// 	std::cout << std::endl;
// }

// template<typename T, typename T2>
// void write(Array<T> &obj, T2 const &array, int size)
// {
// 	for (int i = 0; i < size; i++)
// 		obj[i] = array[i];
// }

// int main() //Verify deep copy
// {
// 	Array<int> *a1 = new Array<int>(); //When initializing integers, float or double in c++, they will automatically be set to zero
// 	Array<int> *a2 = new Array<int>(10);
// 	Array<float> *a3 = new Array<float>();
// 	Array<float> *a4 = new Array<float>(10);
// 	float w[4] = {1, 2, 3, 4};
// 	Array<char> *a5 = new Array<char>(); //Chars are also set to zero, thus through ascii values they are not visible in stdoutput
// 	Array<char> a6(10);
// 	Array<std::string> *a7 = new Array<std::string>(); //Chars are also set to zero, thus through ascii values they are not visible in stdoutput
// 	Array<std::string> *a8 = new Array<std::string>(10);

// 	P("~~Verify const type not able to write to it~~"); //Should create compilation time error, set in comment to continue with main
// 	const Array<int> c(10); //Const classes only enter member-function that end with const keyword, you can create a member-function overload based on this end keyword, so you have control over the return type of functions for const or non-const classes
// 	std::cout << c[0] << std::endl;
// 	c[0] = 6;
// 	std::cout << c[0] << std::endl;
// 	P("~~Integers~~");
// 	std::cout << a1->size() << std::endl;
// 	show(*a1, a1->size());
// 	std::cout << a2->size() << std::endl;
// 	show(*a2, a2->size());
// 	P("~~Floats, write in it~~");
// 	std::cout << a3->size() << std::endl;
// 	show(*a3, a3->size());
// 	write(*a4, w, 4);
// 	std::cout << a4->size() << std::endl;
// 	show(*a4, a4->size());
// 	P("~~Char, write in it~~");
// 	std::cout << a5->size() << std::endl;
// 	show(*a5, a5->size());
// 	write(a6, std::string("hello world"), 10);
// 	std::cout << a6.size() << std::endl;
// 	show(a6, a6.size());
// 	P("~~Complex type, write in it~~");
// 	std::cout << a7->size() << std::endl;
// 	show(*a7, a7->size());
// 	write(*a8, std::string("hello world"), 10);
// 	std::cout << a8->size() << std::endl;
// 	show(*a8, a8->size());
// 	P("~~Setting empty integer array equal to size10 integer array, with deep copy~~"); //Arrays of different types cannot be copied error at compilation
// 	*a1 = *a2;
// 	std::cout << a1->size() << std::endl;
// 	show(*a1, a1->size());
// 	P("~~Going  out of range~~"); ; //!!!!!!!!!!!!OUT OF RANGE SEGFAULT CALL PUT IN COMMENT TO SEE END
// 	try
// 	{
// 		show(*a1,a1->size() + 1);
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	try
// 	{
// 		show(*a4,a4->size() + 2);
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	try
// 	{
// 		write(*a8, std::string("hello world"), 11);
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	try
// 	{
// 		std::cout << a6[-1];
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
	
// 	P("~~Delete all~~"); //If copy was not deep, delete of both a1 and a2 would not be possible as they delete their array in deconstructor
// 	delete a1;
// 	delete a2;
// 	delete a3;
// 	delete a4;
// 	delete a5;
// 	delete a7;
// 	delete a8;
// }
