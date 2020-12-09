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
	cout << "\n" << R_RED << "TESTING CONSTRUCTORS AND ASSIGNATION" << NC << "\n\n";

	FragTrap claptrap("CP-TP");
	FragTrap cptp2(claptrap);
	FragTrap cptp3("TUCK");

	cout << "My name is " << cptp2.getName() << "\n";
	cout << "My name is " << cptp3.getName() << "\n";
	cptp3 = claptrap;
	cout << "Now my name is " << cptp2.getName() << "\n";
	cout << "Now my name is " << cptp3.getName() << "\n";

	cout << "\n" << R_RED << "ACTION" << NC << "\n\n";

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
	cout << "\n" << R_RED << "END OF SIMULATION" << NC << "\n\n";
	return 0;
}