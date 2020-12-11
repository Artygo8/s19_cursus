/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 16:47:03 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/04 16:47:03 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"

// Coplien 	////////////////////////////////////////////////////////////////////

PowerFist::PowerFist() : AWeapon("Power Fist", 50, 8)
{
	std::cout << "Default constructor for PowerFist called" << std::endl;
}

PowerFist::PowerFist(const PowerFist &source) : AWeapon(source)
{
	std::cout << "Copy constructor for PowerFist called" << std::endl;
}

PowerFist::~PowerFist()
{
	std::cout << "Destructor for PowerFist called" << std::endl;
}

PowerFist& PowerFist::operator = (const PowerFist &source)
{
	std::cout << "Assignations operator for PowerFist called" << std::endl;
	return *this;
}

// stream //////////////////////////////////////////////////////////////////////

std::ostream &operator<<(std::ostream &out, PowerFist const &obj)
{
	out << obj.getName();
	return out;
}

void	attack()
{
	std::cout << "* pschhh... SBAM ! *" << std::endl;
}
