/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 18:49:08 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/03 18:49:08 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(int argc, char const *argv[])
{
	{
		ClapTrap claptrap(100,100,100,100,1,"CPTP",10,10,5);
		claptrap.rangedAttack("Psycho Midget");
		claptrap.meleeAttack("Giant Skag");
		claptrap.takeDamage(10);
		claptrap.takeDamage(10);
		claptrap.takeDamage(90);
		claptrap.takeDamage(40);
		claptrap.beRepaired(50);
		claptrap.takeDamage(90);
		claptrap.meleeAttack("Giant Skag");
	}
	cout << '\n';
	{
		ScavTrap scavtrap("MIKE");
		scavtrap.rangedAttack("Psycho Midget");
		scavtrap.meleeAttack("Giant Skag");
		scavtrap.takeDamage(10);
		scavtrap.takeDamage(10);
		scavtrap.takeDamage(90);
		scavtrap.takeDamage(40);
		scavtrap.beRepaired(50);
		scavtrap.challengeNewcomer();
		scavtrap.challengeNewcomer();
		scavtrap.challengeNewcomer();
		scavtrap.challengeNewcomer();
		scavtrap.challengeNewcomer();
		scavtrap.challengeNewcomer();
		scavtrap.takeDamage(90);
		scavtrap.meleeAttack("Giant Skag");
	}
	cout << '\n';
	{
		FragTrap fragtrap("JOHN");
		fragtrap.rangedAttack("Psycho Midget");
		fragtrap.meleeAttack("Giant Skag");
		fragtrap.takeDamage(10);
		fragtrap.takeDamage(10);
		fragtrap.takeDamage(90);
		fragtrap.takeDamage(40);
		fragtrap.beRepaired(50);
		fragtrap.vaulthunter_dot_exe("Guardian");
		fragtrap.vaulthunter_dot_exe("Guardian");
		fragtrap.vaulthunter_dot_exe("Guardian");
		fragtrap.vaulthunter_dot_exe("Guardian");
		fragtrap.vaulthunter_dot_exe("Guardian");
		fragtrap.vaulthunter_dot_exe("Guardian");
		fragtrap.takeDamage(90);
		fragtrap.meleeAttack("Giant Skag");
	}
	return 0;
}