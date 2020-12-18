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

#define TITLE_BLU(str) std::cout << R_BLU << str << NC << std::endl
#define TITLE_MGN(str) std::cout << R_MGN << str << NC << std::endl

int main()
{
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;

	TITLE_BLU("First Squad, 2 people");

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


	TITLE_BLU("Second Squad, deep copy with 2 more people");

	ISpaceMarine* john = new AssaultTerminator;
	Squad* vlc2 = new Squad(*vlc);
	vlc2->push(john);
	vlc2->push(jim->clone());

	for (int i = 0; i < vlc2->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc2->getUnit(i);
		std::cout << R_YLW << cur << NC << std::endl;
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}

	TITLE_BLU("Third Squad, deep copy by assignation");

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
	delete vlc3;

	return 0;
}