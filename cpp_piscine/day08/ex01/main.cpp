/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 18:20:17 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/26 18:20:17 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

int main()
{
	{
		TITLE("__FIRST_TEST__");
		Span sp(4);

		TITLE("show what we have");
		try
		{
			for (int i = 0; i < 10; i++)
				std::cout << sp[i] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		TITLE("fill the Span");
		try
		{
			for (int i = -2; i < 10; i++)
				sp.addNumber(i);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		TITLE("show what we have");
		try
		{
			for (int i = 0; i < 10; i++)
				std::cout << sp[i] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		TITLE("__TESTING_ITERATOR_CREATION__");
		int myints[] = { 1, 2, 19, 42, 27 };
		Span sp(myints, myints + 5);

		TITLE("show what we have");
		try
		{
			for (int i = 0; i < 10; i++)
				std::cout << sp[i] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		TITLE("__SPAN_TEST__");
		TITLE("1 element {19}");
		Span sp(1);
		sp.addNumber(19);

		try
		{
			std::cout << "longest span: " << sp.longestSpan() << std::endl;
			std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		TITLE("2 elements {19, 42}");
		Span sp(2);
		sp.addNumber(19);
		sp.addNumber(42);

		try
		{
			std::cout << "longest span: " << sp.longestSpan() << std::endl;
			std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		TITLE("5 elements { 2, 19, 42, 27, 26 }");
		int myints[] = { 2, 19, 42, 27, 25 };
		Span sp(myints, myints + 5);

		try
		{
			std::cout << "longest span: " << sp.longestSpan() << std::endl;
			std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	return 0;
}