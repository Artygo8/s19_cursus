/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 16:47:03 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/04 16:47:03 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "Enemy.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "Character.hpp"

#include "UselessWeapon.hpp"
#include "Duck.hpp"

#define TITLE_BLU(str) std::cout << R_BLU << str << NC << std::endl
#define TITLE_MGN(str) std::cout << R_MGN << str << NC << std::endl

int main()
{

	{
		TITLE_BLU("Create new stuffs then test operator<<");
		Character *me = new Character("me");
		std::cout << *me;
		Enemy *rs = new RadScorpion();
		std::cout << *rs;
		Enemy *sm = new SuperMutant();
		std::cout << *sm;
		AWeapon *pr = new PlasmaRifle();
		std::cout << *pr << std::endl;
		AWeapon *pf = new PowerFist();
		std::cout << *pf << std::endl;

		TITLE_BLU("Try to attack with no weapon");
		me->attack(rs);
		std::cout << *rs;

		TITLE_BLU("Equip Plasma Rifle");
		me->equip(pr);
		std::cout << *me;

		TITLE_BLU("Try to attack with Plasma Rifle");
		me->attack(rs);
		std::cout << *rs;
		std::cout << *me;

		TITLE_BLU("Equip Power Fist");
		me->equip(pf);
		std::cout << *me;

		TITLE_BLU("Attack SuperMutant");
		me->attack(sm);
		std::cout << *sm;
		std::cout << *me;

		TITLE_BLU("Recover AP");
		me->recoverAP();
		std::cout << *me;

		TITLE_BLU("Attack SuperMutant");
		me->attack(sm);
		std::cout << *sm;
		std::cout << *me;

		TITLE_BLU("Attack SuperMutant");
		me->attack(sm);
		std::cout << *sm;
		std::cout << *me;

		TITLE_BLU("Attack SuperMutant");
		me->attack(sm);
		std::cout << *me;

		TITLE_BLU("Delete all that is left");
		delete(pr);
		delete(pf);
		delete(rs);
		delete(me);
	}

	{
		TITLE_MGN("Create Custom objects:");
		Character me("me");
		std::cout << me;
		Enemy *ducky = new Duck();
		std::cout << *ducky;
		Enemy *duckyToo = new Duck();
		std::cout << *duckyToo;
		AWeapon *uw = new UselessWeapon();
		std::cout << *uw << std::endl;
		AWeapon *pr = new PlasmaRifle();
		std::cout << *pr << std::endl;

		TITLE_MGN("Equip Useless Weapon");
		me.equip(uw);
		std::cout << me;

		TITLE_MGN("Attack the first duck");
		me.attack(ducky);
		std::cout << me;
		
		TITLE_MGN("Try to attack the second duck");
		me.attack(duckyToo);
		std::cout << me;

		TITLE_MGN("Change weapon");
		me.equip(pr);
		std::cout << me;
		TITLE_MGN("Attack the second duck");
		me.attack(duckyToo);
		std::cout << me;

		TITLE_MGN("Delete what's left");
		delete uw;
		delete pr;
	}

	return (0);
}