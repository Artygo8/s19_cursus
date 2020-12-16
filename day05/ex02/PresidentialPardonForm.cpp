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
Form("PPF " + cible, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &source) :
Form(source)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator = (const PresidentialPardonForm &source)
{
	*this = source;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

// others //////////////////////////////////////////////////////////////////////

