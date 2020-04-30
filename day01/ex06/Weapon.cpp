/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 11:08:44 by agossuin          #+#    #+#             */
/*   Updated: 2020/04/29 11:43:25 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string i)
{
	info = i;
	ad_info = &info;
}

Weapon::~Weapon(){}

void			Weapon::setType(std::string i)
{
	info = i;
	ad_info = &info;
}

std::string		Weapon::getType()
{
	return *ad_info;
}
