/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 00:00:23 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/15 00:00:23 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

// Coplien's form //////////////////////////////////////////////////////////////

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure &source) : AMateria("cure")
{
	this->setXP(source.getXP());
}

Cure& Cure::operator = (const Cure &source)
{
	Cure();
	this->setXP(source.getXP());
	return *this;
}

Cure::~Cure()
{
}

// others //////////////////////////////////////////////////////////////////////

Cure* Cure::clone() const
{
	Cure *clone = new Cure(*this);
	return clone;
}

void Cure::use(ICharacter& target)
{
	std::cout << GRN << "* heals " << target.getName() << "’s wounds *" << NC << std::endl;
	this->AMateria::use(target);
}
