/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 13:15:29 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/16 13:15:29 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// Coplien's form //////////////////////////////////////////////////////////////

RobotomyRequestForm::RobotomyRequestForm(std::string cible) :
Form("RobotomyRequestForm", 72, 45, cible)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &source) :
Form(source)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator = (const RobotomyRequestForm &source)
{
	*this = source;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

// others //////////////////////////////////////////////////////////////////////

void	RobotomyRequestForm::execute (Bureaucrat const & executor) const
{
	Form::execute(executor);
	std::cout << "Brzzz Brzzz Brzzz" << std::endl;
	std::cout << getTarget() << " was robotomized." << std::endl;
}
