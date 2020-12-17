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

int main()
{

	{
		std::cout << R_BLU << "Create character:" << NC << std::endl;
		Character *me = new Character("me");
		std::cout << *me;

		std::cout << R_BLU << "Create enemies:" << NC << std::endl;
		Enemy *rs = new RadScorpion();
		Enemy *sm = new SuperMutant();

		std::cout << R_BLU << "Try to attack with no weapon:" << NC << std::endl;
		std::cout << "HP of the " << rs->getType() << " : " << rs->getHP() << std::endl;
		me->attack(rs);
		std::cout << "HP of the " << rs->getType() << " : " << rs->getHP() << std::endl;

		std::cout << "HP of the " << sm->getType() << " : " << sm->getHP() << std::endl;
		me->attack(sm);
		std::cout << "HP of the " << sm->getType() << " : " << sm->getHP() << std::endl;

		std::cout << R_BLU << "Equip weapon:" << NC << std::endl;
		AWeapon *pr = new PlasmaRifle();
		me->equip(pr);
		std::cout << *me;

		std::cout << R_BLU << "Try to attack with weapon:" << NC << std::endl;
		std::cout << "HP of the " << rs->getType() << " : " << rs->getHP() << std::endl;
		me->attack(rs);
		std::cout << "HP of the " << rs->getType() << " : " << rs->getHP() << std::endl;
		std::cout << *me;

		std::cout << R_BLU << "Equip new weapon:" << NC << std::endl;
		AWeapon *pf = new PowerFist();
		me->equip(pf);
		std::cout << *me;

		std::cout << R_BLU << "Kill SuperMutant:" << NC << std::endl;
		std::cout << "HP of the " << sm->getType() << " : " << sm->getHP() << std::endl;
		me->attack(sm);
		std::cout << *me;
		me->recoverAP();

		std::cout << "HP of the " << sm->getType() << " : " << sm->getHP() << std::endl;
		me->attack(sm);
		std::cout << *me;
		me->recoverAP();

		std::cout << "HP of the " << sm->getType() << " : " << sm->getHP() << std::endl;
		me->attack(sm);
		std::cout << *me;
		me->recoverAP();
		std::cout << "HP of the " << sm->getType() << " : " << sm->getHP() << std::endl;
		me->attack(sm);
		std::cout << *me;

		std::cout << R_BLU << "Delete all:" << NC << std::endl;
		delete(pr);
		delete(pf);
		delete(rs);
		delete(me);
		// I dont delete the SuperMutant 'sm', because it was already killed, deleted
	}

	{
		std::cout << R_BLU << "Custom objects:" << NC << std::endl;
		Character me("me");
		Enemy *ducky = new Duck();
		Enemy *duckyToo = new Duck();
		AWeapon *uw = new UselessWeapon();
		AWeapon *pr = new PlasmaRifle();

		std::cout << me;
		me.equip(uw);
		std::cout << me;
		me.attack(ducky);
		std::cout << me;
		
		std::cout << R_BLU << "Trying attack the other duck:" << NC << std::endl;
		me.attack(duckyToo);
		std::cout << me;

		std::cout << R_BLU << "change weapon:" << NC << std::endl;
		me.equip(pr);
		me.attack(duckyToo);
		std::cout << me;

		delete uw;
		delete pr;
	}

	return (0);
}