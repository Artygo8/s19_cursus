/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 14:41:47 by agossuin          #+#    #+#             */
/*   Updated: 2020/04/28 15:30:49 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int N)
{
	zombieHorde = new Zombie[N];

	n = N;
	srand(time(NULL));
	std::cout << "*** Zombie horde incoming ***" << '\n';
}

ZombieHorde::~ZombieHorde()
{
	delete[] zombieHorde;
	std::cout << "*** Horde is even more dead ***" << '\n';
}

void	ZombieHorde::announce()
{
	for (size_t i = 0; i < n; i++)
		zombieHorde[i].announce();
}
