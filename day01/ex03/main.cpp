/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 11:58:12 by agossuin          #+#    #+#             */
/*   Updated: 2020/04/28 15:14:28 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

int main(void)
{
	ZombieHorde	*Zhorde = new ZombieHorde(6);
	Zhorde->announce();
	delete Zhorde;

	return (0);
}
