/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 11:33:35 by agossuin          #+#    #+#             */
/*   Updated: 2020/04/28 13:38:20 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce()
{
	std::cout << '<' << getName() << " (" << getType() << ")> Braiiiiiiinnnssss...\n";
}

std::string Zombie::getName() const
{
	return name;
}

std::string Zombie::getType() const
{
	return type;
}

Zombie::Zombie()
{
	std::cout << "+" << '\n';
}

Zombie::Zombie(std::string const ztype, std::string const zname)
	: type(ztype), name(zname)
{
	std::cout << "+" << '\n';
}

Zombie::~Zombie()
{
	std::cout << "-" << '\n';
}
