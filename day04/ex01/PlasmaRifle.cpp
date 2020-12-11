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

// Coplien /////////////////////////////////////////////////////////////////////

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 21, 5)
{
	std::cout << "Default constructor for PlasmaRifle called" << std::endl;
}

PlasmaRifle::PlasmaRifle(const PlasmaRifle &source) : AWeapon(source)
{
	std::cout << "Copy constructor for PlasmaRifle called" << std::endl;
}

PlasmaRifle::~PlasmaRifle()
{
	std::cout << "Destructor for PlasmaRifle called" << std::endl;
}

PlasmaRifle& PlasmaRifle::operator = (const PlasmaRifle &source)
{
	std::cout << "Assignations operator for PlasmaRifle called" << std::endl;
	return *this;
}

// stream //////////////////////////////////////////////////////////////////////

std::ostream &operator<<(std::ostream &out, PlasmaRifle const &obj)
{
	out << obj.getName();
	return out;
}

void	attack()
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
