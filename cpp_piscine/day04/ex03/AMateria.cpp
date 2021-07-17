/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 00:00:23 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/15 00:00:23 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// Coplien's form //////////////////////////////////////////////////////////////

AMateria::AMateria(std::string const & type) : type(type), _xp(0) {}

AMateria::AMateria(const AMateria &source) : type(source.type), _xp(source._xp) {}

AMateria& AMateria::operator = (const AMateria &source)
{
	this->_xp = source._xp;
	return *this;
}

AMateria::~AMateria()
{
}

// others //////////////////////////////////////////////////////////////////////

std::string const & AMateria::getType() const
{
	return type;
}

unsigned int AMateria::getXP() const
{
	return _xp;
}

void		AMateria::setXP(unsigned int xp)
{
	_xp = xp;
}

void AMateria::use(ICharacter& target)
{
	(void)target;
	_xp += 10;
}

std::ostream &operator<<(std::ostream &out, AMateria const &obj)
{
	out << "this Materia is of type " << obj.getType() << " and has " << obj.getXP() << " XP\n";
	return out;
}