/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 20:59:03 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/15 20:59:03 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// Coplien's form //////////////////////////////////////////////////////////////

Intern::Intern()
{
}

Intern::Intern(const Intern &source)
{
	*this = source;
}

Intern& Intern::operator = (const Intern &source)
{
    (void)source;
	return *this;
}

Intern::~Intern()
{
}

// exceptions //////////////////////////////////////////////////////////////////

char const *Intern::UnrecognizedFormException::what() const throw()
{
	return "This form seems to be unknowned";
}

// others //////////////////////////////////////////////////////////////////////

Form    *makePresidentialPardonForm(std::string target)
{
    return new PresidentialPardonForm(target);
}

Form    *makeRobotomyRequestForm(std::string target)
{
    return new RobotomyRequestForm(target);
}

Form    *makeShrubberyCreationForm(std::string target)
{
    return new ShrubberyCreationForm(target);
}

Form    *Intern::makeForm(std::string name, std::string target)
{
    struct s_maker all_forms[3] = {
        {"presidential pardon", makePresidentialPardonForm},
        {"robotomy request", makeRobotomyRequestForm},
        {"shrubbery creation", makeShrubberyCreationForm}
    };

    for (int i = 0; i < 3; i++)
    {
        if (all_forms[i].name == name)
            return (all_forms[i].function(target));
    }
    throw UnrecognizedFormException();
}