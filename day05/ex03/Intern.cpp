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
	*this = source;
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

Form    *Intern::makeForm(std::string name, std::string target)
{
    Form *result = nullptr;

    Form   *all_forms[3] = {
        new PresidentialPardonForm(target),
        new RobotomyRequestForm(target),
        new ShrubberyCreationForm(target),
    };

    for (int i = 0; i < 3; i++)
    {
        if (all_forms[i]->getName() == name)
            result = all_forms[i];
        else
            delete all_forms[i];
    }
    if (result == nullptr)
        throw UnrecognizedFormException();
    return result;
}