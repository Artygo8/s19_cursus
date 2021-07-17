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
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat arthur("Arthur", 1);
	Bureaucrat john("John", 54);
	Bureaucrat patrick("Patrick", 140);

	PresidentialPardonForm ppf("My Dog");
	RobotomyRequestForm rrf("My Neighbour");
	ShrubberyCreationForm scf("Home");

	TITLE("John tries to EXECUTE");
	john.executeForm(ppf);
	john.executeForm(rrf);
	john.executeForm(scf);

	TITLE("Patrick tries to SIGN");
	patrick.signForm(ppf);
	patrick.signForm(rrf);
	patrick.signForm(scf);

	TITLE("John tries to EXECUTE");
	john.executeForm(ppf);
	john.executeForm(rrf);
	john.executeForm(scf);

	TITLE("John tries to SIGN");
	john.signForm(ppf);
	john.signForm(rrf);
	john.signForm(scf);

	TITLE("Arthur does everything cause he is the boss");
	arthur.signForm(ppf);
	arthur.executeForm(ppf);
	arthur.signForm(rrf);
	arthur.executeForm(rrf);
	arthur.signForm(scf);
	arthur.executeForm(scf);

	return 0;
}