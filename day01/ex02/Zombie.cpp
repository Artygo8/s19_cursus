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
	std::cout << '<' << name << " (" << type << ")> Braiiiiiiinnnssss...\n";
}

Zombie::Zombie()
{
	type = type;
	name = name;
	std::cout << "+" << '\n';
}

Zombie::~Zombie()
{
	std::cout << "-" << '\n';
}
