/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 16:47:03 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/04 16:47:03 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

// Contructors /////////////////////////////////////////////////////////////////

AWeapon::AWeapon(std::string const &name, int damage, int apcost) :
name(name), damage(damage), apcost(apcost)
{
	std::cout << "Default constructor for AWeapon called" << std::endl;
}

AWeapon::AWeapon(const AWeapon &source) :
name(source.name), damage(source.damage), apcost(source.apcost)
{
	std::cout << "Copy constructor for AWeapon called" << std::endl;
}

AWeapon::~AWeapon()
{
	std::cout << "Destructor for AWeapon called" << std::endl;
}

// Operators ///////////////////////////////////////////////////////////////////

AWeapon& AWeapon::operator = (const AWeapon &source)
{
	std::cout << "Assignations operator for AWeapon called" << std::endl;
	return *this;
}

std::string	AWeapon::getName() const//generic function
{
	return name;
}

// stream //////////////////////////////////////////////////////////////////////

std::ostream &operator<<(std::ostream &out, AWeapon const &obj)
{
	out << obj.getName();
	return out;
}

