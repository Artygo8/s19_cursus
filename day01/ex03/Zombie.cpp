/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 11:33:35 by agossuin          #+#    #+#             */
/*   Updated: 2020/04/28 15:23:54 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

std::string		random_name()
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
	std::cout << '<' << name << " (" << type << ")> Braiiiiiiinnnssss...\n";
}

Zombie::Zombie()
{
	type = type;
	name = random_name();
	std::cout << "+" << '\n';
}

Zombie::~Zombie()
{
	std::cout << "-" << '\n';
}
