/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 20:59:03 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/15 20:59:03 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	test_high_grades(int start, int amount)
{
	int grade;
	Bureaucrat john("John", grade = start);

	for (int i = 0; i < 3; i++)
	{
		try
		{
			john.incGrade();
			std::cout << john << " says hello." << std::endl;
		}
		catch (char const * msg)
		{
			std::cout << RED << msg << NC << std::endl;
		}
	}
}

void	test_low_grades(int start, int amount)
{
	int grade;
	Bureaucrat john("John", grade = start);

	for (int i = 0; i < amount; i++)
	{
		try
		{
			john.decGrade();
			std::cout << john << " says hello." << std::endl;
		}
		catch (char const * msg)
		{
			std::cout << RED << msg << NC << std::endl;
		}
	}
}

void	test_random_grades(int amount)
{
	for (int i = 0; i < amount; i++)
	{
		int grade = (rand() % 250) - 50;

		try
		{
			std::cout << GRN << "grade is " << grade << NC << "\n";
			Bureaucrat john("John", grade);
			std::cout << john << " says hello." << std::endl;
		}
		catch (char const * msg)
		{
			std::cout << RED << msg << NC << std::endl;
		}
	}
}

int main(int argc, char const *argv[])
{
	srand(time(NULL));

	TITLE("5 random grades");
	test_random_grades(5);

	TITLE("edge cases");
	test_high_grades(3, 3);
	test_low_grades(148, 3);

	return 0;
}