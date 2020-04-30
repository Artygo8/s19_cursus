/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 10:21:57 by agossuin          #+#    #+#             */
/*   Updated: 2020/04/29 11:16:31 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string n, Weapon weap)
{
	name = n;
	wp = &weap;
	std::cout << name << " was created" << '\n';
	std::cout << "his weapon is " << wp->getType() << '\n';
}

HumanA::~HumanA()
{
	std::cout << name << " is being deleted" << '\n';
}

void		HumanA::attack()
{
	std::cout << name << " is attacking with " << wp->getType() << '\n';
}
