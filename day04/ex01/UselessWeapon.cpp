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

UselessWeapon::UselessWeapon() : AWeapon("Useless Weapon", 1, 30)
{
	// std::cout << "Default constructor for UselessWeapon called" << std::endl;
}

UselessWeapon::UselessWeapon(const UselessWeapon &source) : AWeapon(source)
{
	// std::cout << "Copy constructor for UselessWeapon called" << std::endl;
}

UselessWeapon::~UselessWeapon()
{
	// std::cout << "Destructor for UselessWeapon called" << std::endl;
}

UselessWeapon& UselessWeapon::operator = (const UselessWeapon &source)
{
	// std::cout << "Assignations operator for UselessWeapon called" << std::endl;
	*this = source;
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
