/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 11:58:12 by agossuin          #+#    #+#             */
/*   Updated: 2020/04/28 13:34:51 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

int main(void)
{
	ZombieEvent	Zevent = ZombieEvent();
	Zombie		*z = Zevent.newZombie("John");

	z->announce();
	delete z;

	Zevent.randomChump();
	Zevent.randomChump();

	Zevent.setZombieType("little one");
	Zevent.randomChump();
	Zevent.randomChump();
	Zevent.randomChump();
	Zevent.randomChump();
	return (0);
}
