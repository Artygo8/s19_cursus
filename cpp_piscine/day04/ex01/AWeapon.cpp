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
name(name), damage(damage), apcost(apcost) {}

AWeapon::AWeapon(const AWeapon &source) :
name(source.name), damage(source.damage), apcost(source.apcost) {}

AWeapon::~AWeapon() {}

AWeapon& AWeapon::operator = (const AWeapon &source)
{
	this->name = source.name;
	this->damage = source.damage;
	this->apcost = source.apcost;
	return *this;
}

// set-get /////////////////////////////////////////////////////////////////////

std::string const	AWeapon::getName() const
{
	return name;
}

int					AWeapon::getAPCost() const
{
	return apcost;
}

int					AWeapon::getDamage() const
{
	return damage;
}

// stream //////////////////////////////////////////////////////////////////////

std::ostream &operator<<(std::ostream &out, AWeapon const &obj)
{
	out << obj.getName();
	return out;
}
