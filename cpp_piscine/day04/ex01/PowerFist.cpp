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

PowerFist::PowerFist() : AWeapon("Power Fist", 50, 8) {}

PowerFist::PowerFist(const PowerFist &source) : AWeapon(source) {}

PowerFist::~PowerFist() {}

PowerFist& PowerFist::operator = (const PowerFist &source)
{
	AWeapon::operator= (source);
	return *this;
}

// stream //////////////////////////////////////////////////////////////////////

std::ostream &operator<<(std::ostream &out, PowerFist const &obj)
{
	out << obj.getName();
	return out;
}

void	PowerFist::attack() const
{
	std::cout << "* pschhh... SBAM ! *" << std::endl;
}
