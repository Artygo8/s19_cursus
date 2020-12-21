/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 13:15:29 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/16 13:15:29 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{

	try
	{
		TITLE("Initial values");
		Intern someRandomIntern;
		Form* rrf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << MGN << *rrf << NC << std::endl;

		Bureaucrat arthur("Arthur", 1);
		std::cout << MGN << arthur << NC << std::endl;
		Bureaucrat john("John", 54);
		std::cout << MGN << john << NC << std::endl;
		Bureaucrat patrick("Patrick", 140);
		std::cout << MGN << patrick << NC << std::endl;

		std::cout << std::endl;

		TITLE("Patrick tries to SIGN");
		patrick.signForm(*rrf);
		std::cout << std::endl;

		TITLE("John tries to SIGN");
		john.signForm(*rrf);
		std::cout << std::endl;

		TITLE("John tries to EXECUTE");
		john.executeForm(*rrf);
		std::cout << std::endl;

		TITLE("Arthur does everything cause he is the boss");
		arthur.signForm(*rrf);
		arthur.executeForm(*rrf);
		std::cout << std::endl;

		TITLE("Patrick tries to SIGN");
		patrick.signForm(*rrf);
		std::cout << std::endl;

		delete rrf;

		TITLE("create a form COUCOU");
		rrf = someRandomIntern.makeForm("COUCOU", "HOME");
		delete rrf;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}