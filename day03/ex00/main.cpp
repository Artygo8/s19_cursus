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

int main(int argc, char const *argv[])
{
	FragTrap claptrap("CP-TP");

	claptrap.rangedAttack("Psycho Midget");
	claptrap.meleeAttack("Giant Skag");
	claptrap.takeDamage(10);
	claptrap.takeDamage(10);
	claptrap.takeDamage(90);
	claptrap.takeDamage(40);
	claptrap.beRepaired(50);
	claptrap.vaulthunter_dot_exe("Guardian");
	claptrap.vaulthunter_dot_exe("Guardian");
	claptrap.vaulthunter_dot_exe("Guardian");
	claptrap.vaulthunter_dot_exe("Guardian");
	claptrap.vaulthunter_dot_exe("Guardian");
	claptrap.vaulthunter_dot_exe("Guardian");
	claptrap.takeDamage(90);
	claptrap.meleeAttack("Giant Skag");
	return 0;
}