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

const std::string	random_name()
{
	char			c;
	int				max;
	std::string		name;

	max = rand() % 4;
	name += 'A' + rand() % 26;
	for (int i = 0; i < max + 4; ++i)
		name += 'a' + rand() % 26;
	return name;
}

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
	type = "big one";
	name = random_name();
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
