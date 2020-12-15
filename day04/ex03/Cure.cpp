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

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(const Cure &source) : AMateria(source)
{
}

Cure& Cure::operator = (const Cure &source)
{
	*this = source;
	return *this;
}

Cure::~Cure()
{
}

// others //////////////////////////////////////////////////////////////////////

std::string const & Cure::getType() const
{
	return "cure";
} //Returns the materia type

unsigned int Cure::getXP() const
{
	return this->AMateria::getXP();
} //Returns the Materia's XP

AMateria* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << GRN << "* heals NOM’s wounds *" << NC << std::endl;
	this->AMateria::use(target);
}
