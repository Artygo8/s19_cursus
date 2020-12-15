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

AMateria::AMateria(std::string const & type) : type(type), _xp(0)
{

}

AMateria::AMateria(const AMateria &source)
{
	this->type = source.type;
	this->_xp = source._xp;
}

AMateria& AMateria::operator = (const AMateria &source)
{
	*this = source;
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

void AMateria::use(ICharacter& target)
{
	_xp += 10;
}
