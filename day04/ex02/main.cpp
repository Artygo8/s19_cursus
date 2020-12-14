/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 20:30:35 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/14 20:30:35 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"
#include "ISpaceMarine.hpp"
#include "ISquad.hpp"

int main(int argc, char const *argv[])
{
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;

	std::cout << R_RED << "First Squad, 2 people" << NC << std::endl;

	Squad* vlc = new Squad;
	vlc->push(bob);
	vlc->push(jim);

	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		std::cout << R_YLW << cur << NC << std::endl;
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}


	std::cout << R_RED << "Second Squad, deep copy with 2 more people" << NC << std::endl;

	ISpaceMarine* john = new AssaultTerminator;
	Squad* vlc2 = new Squad(*vlc);
	vlc2->push(john);
	// We can't add jim because he is in the other squad but we can add clones,
	// vlc2->push(jim);
	vlc2->push(jim->clone());

	for (int i = 0; i < vlc2->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc2->getUnit(i);
		std::cout << R_YLW << cur << NC << std::endl;
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}

	std::cout << R_RED << "Third Squad, shallow copy of the first one" << NC << std::endl;

	Squad *vlc3 = vlc;

	for (int i = 0; i < vlc3->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc3->getUnit(i);
		std::cout << R_YLW << cur << NC << std::endl;
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}

	delete vlc;
	delete vlc2;

	return 0;
}