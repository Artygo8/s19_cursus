/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 22:35:53 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/15 22:35:53 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://stackoverflow.com/questions/583076/c-c-changing-the-value-of-a-const#:~:text=A%20const%20variable%20can%20be,be%20modified%20through%20its%20pointer.

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	incrementing_grade()
{
	Form a("28a", 19, 2);
	Bureaucrat john("John", 23);

	try
	{
		while (!a.getIsSigned())
		{
			john.signForm(a);
			john.incGrade();
		}
	}
	catch (std::exception &e)
	{
		std::cerr << "The program failed because " << e.what() << std::endl;
	}
}

void	decrementing_grade()
{
	Form a("28a", 19, 2);
	Bureaucrat john("John", 148);

	try
	{
		while (!a.getIsSigned())
		{
			john.signForm(a);
			john.decGrade();
		}
	}
	catch (std::exception &e)
	{
		std::cerr << "The function failed because " << e.what() << std::endl;
	}
}

int main(int argc, char const *argv[])
{
	incrementing_grade();
	decrementing_grade();

	return 0;
}