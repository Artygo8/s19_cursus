/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 13:15:29 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/16 13:15:29 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Coplien's form //////////////////////////////////////////////////////////////

PresidentialPardonForm::PresidentialPardonForm(std::string cible) :
Form("PresidentialPardonForm", 25, 5, cible)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &source) :
Form(source)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator = (const PresidentialPardonForm &source)
{
	(void)source;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

// others //////////////////////////////////////////////////////////////////////

void	PresidentialPardonForm::execute (Bureaucrat const & executor) const
{
	if (!this->getIsSigned())
		throw UnsignedFormException();
	if (this->getExecGrade() < executor.getGrade())
		throw GradeTooHighException();
	std::cout << getTarget() << " was forgiven by Zafod Beeblebrox." << std::endl;
}
