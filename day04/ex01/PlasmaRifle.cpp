/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 16:47:03 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/04 16:47:03 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"

// Contructors /////////////////////////////////////////////////////////////////

PlasmaRifle::PlasmaRifle()
{
	std::cout << "Default constructor for PlasmaRifle called" << std::endl;
}

PlasmaRifle::PlasmaRifle(const PlasmaRifle &source)
{
	std::cout << "Copy constructor for PlasmaRifle called" << std::endl;
}

PlasmaRifle::~PlasmaRifle()
{
	std::cout << "Destructor for PlasmaRifle called" << std::endl;
}

// Operators ///////////////////////////////////////////////////////////////////

PlasmaRifle& PlasmaRifle::operator = (const PlasmaRifle &source)
{
	std::cout << "Assignations operator for PlasmaRifle called" << std::endl;
	return *this;
}

// set-get ///////////////////////////////////////////////////////////////////////

void		PlasmaRifle::setName(std::string name) //generic function
{
	name = name;
}

std::string	PlasmaRifle::getName() const//generic function
{
	return name;
}

// stream //////////////////////////////////////////////////////////////////////

std::ostream &operator<<(std::ostream &out, PlasmaRifle const &obj)
{
	out << obj.getName();
	return out;
}

