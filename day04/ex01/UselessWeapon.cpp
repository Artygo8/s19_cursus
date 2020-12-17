/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UselessWeapon.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 16:47:03 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/04 16:47:03 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UselessWeapon.hpp"

// Coplien /////////////////////////////////////////////////////////////////////

UselessWeapon::UselessWeapon() : AWeapon("Useless Weapon", 1, 30) {}

UselessWeapon::UselessWeapon(const UselessWeapon &source) : AWeapon(source) {}

UselessWeapon::~UselessWeapon() {}

UselessWeapon& UselessWeapon::operator = (const UselessWeapon &source)
{
	AWeapon::operator= (source);
	return *this;
}

// stream //////////////////////////////////////////////////////////////////////

std::ostream &operator<<(std::ostream &out, UselessWeapon const &obj)
{
	out << obj.getName();
	return out;
}

void	UselessWeapon::attack() const
{
	std::cout << "* hahahaha *" << std::endl;
}
