/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 12:00:46 by agossuin          #+#    #+#             */
/*   Updated: 2020/04/29 12:30:55 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string n) : name(n)
{
	std::cout << name << " was created" << '\n';
}

HumanB::~HumanB()
{
	std::cout << name << " is being deleted" << '\n';
}

void		HumanB::setWeapon(Weapon weap)
{
	wp = &weap;
}

void		HumanB::attack()
{
	std::cout << name << " is attacking with " << wp->getType() << '\n';
}
