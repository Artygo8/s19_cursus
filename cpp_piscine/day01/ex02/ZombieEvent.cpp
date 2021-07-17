/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 12:30:43 by agossuin          #+#    #+#             */
/*   Updated: 2020/04/28 14:38:48 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent()
{
	std::cout << "*** The appocalypse is starting ***" << '\n';
	srand(time(NULL));
}

ZombieEvent::~ZombieEvent()
{
	std::cout << "*** The appocalypse is ending ***" << '\n';
}

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

void	ZombieEvent::randomChump()
{
	Zombie		z(random_name(), "big one");

	z.announce();
}

void	ZombieEvent::setZombieType(std::string given_type)
{
	type = given_type;
}

Zombie* ZombieEvent::newZombie(std::string name)
{
	Zombie		*z = new Zombie(name, "big one");

	return (z);
}
