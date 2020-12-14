/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 12:00:01 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/04 12:00:01 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

// Coplien ////////////////////////////////////////////////////////////////////

Victim::Victim(std::string n)
{
	this->name = n;
	std::cout << "Some random victim called " << name << " just appeared!" << std::endl;
}

Victim::Victim(const Victim &source)
{
	std::cout << "Copy constructor for Victim called" << std::endl;
}

Victim::~Victim()
{
	std::cout << "Victim " << name << " just died for no apparent reason!" << std::endl;
}

Victim& Victim::operator = (const Victim &source)
{
	std::cout << "Assignations operator for Victim called" << std::endl;
	this->name = source.name;
	return *this;
}

// Utils ///////////////////////////////////////////////////////////////////////

void		Victim::setName(std::string name) //generic function
{
	this->name = name;
}

void Victim::getPolymorphed() const
{
	std::cout << name << " has been turned into a cute little sheep!" << std::endl;
}

std::string Victim::getName() const //generic function
{
	return name;
}

std::ostream &operator<<(std::ostream &out, const Victim &vi)
{
	out << "I'm " << vi.getName() << " and I like otters!" << std::endl;
	return out;
}
