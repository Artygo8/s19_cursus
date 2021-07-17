/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 00:00:23 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/15 00:00:23 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

// Coplien's form //////////////////////////////////////////////////////////////

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(const Ice &source) : AMateria("ice")
{
	this->setXP(source.getXP());
}

Ice& Ice::operator = (const Ice &source)
{
	Ice();
	this->setXP(source.getXP());
	return *this;
}

Ice::~Ice()
{
}

// others //////////////////////////////////////////////////////////////////////

Ice* Ice::clone() const
{
	Ice *clone = new Ice(*this);
	return clone;
}

void Ice::use(ICharacter& target)
{
	std::cout << BLU << "* shoots an ice bolt at " << target.getName() << " *" << NC << std::endl;
	this->AMateria::use(target);
}
