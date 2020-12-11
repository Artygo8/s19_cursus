/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 18:49:08 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/03 18:49:08 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Contructors /////////////////////////////////////////////////////////////////

ScavTrap::ScavTrap()
{
	std::cout << R_BLU << "    I'm Trap, Claptrap. Double oh... Trap. (default constructor)" << NC << std::endl;
}

ScavTrap::ScavTrap(std::string name) :
hp(100),
max_hp(100),
energy(50),
max_energy(50),
lvl(1),
melee(20),
ranged(15),
armor(3)
{
	srand (time(NULL));
	std::cout << R_BLU << "    I'm Trap, Claptrap. Double oh... Trap. (constructor)" << NC << std::endl;
	this->name = name;
}

ScavTrap::ScavTrap(const ScavTrap &source)
{
	std::cout << R_BLU << "    Let's get this party started! (copy)" << NC << std::endl;
	this->setAttributes(source);
}

ScavTrap::~ScavTrap()
{
	std::cout << R_BLU << "    I can see... the code... (destructor)    " << NC << std::endl;
}

// Operators ///////////////////////////////////////////////////////////////////

ScavTrap &ScavTrap::operator=(const ScavTrap &source)
{
	std::cout << R_BLU << "*** Recompiling my combat code! (assignement) ***" << NC << std::endl;
	this->setAttributes(source);
	return *this;
}

// set-get ///////////////////////////////////////////////////////////////////////

void ScavTrap::setAttributes(const ScavTrap &copy) //generic function
{
	this->hp = copy.hp;
	this->max_hp = copy.max_hp;
	this->energy = copy.energy;
	this->max_energy = copy.max_energy;
	this->lvl = copy.lvl;
	this->name = copy.name;
	this->melee = copy.melee;
	this->ranged = copy.ranged;
	this->armor = copy.armor;
}

std::string ScavTrap::getName() //generic function
{
	return this->name;
}

// Actions /////////////////////////////////////////////////////////////////////

void ScavTrap::rangedAttack(std::string const &target)
{
	if (max_hp == 0)
		std::cout << BLU << "--- I am dead... What can I do!? ---" << NC << std::endl;
	else
	{
		std::cout << BLU << "--- Get off my lawn! ---" << NC << std::endl;
		std::cout << "+++ SC4V - TP " << GRN << name << NC << " attacks " << RED << target << "\e[m at range, ";
		std::cout << "causing " << ranged << " points of damage ! +++" << std::endl;
	}
}

void ScavTrap::meleeAttack(std::string const &target)
{
	if (hp == 0)
		std::cout << BLU << "--- I am dead... What can I do!? ---" << NC << std::endl;
	else
	{
		std::cout << BLU << "--- Ready for the PUNCHline?! ---" << NC << std::endl;
		std::cout << "+++ SC4V - TP " << GRN << name << "\e[m attacks " << RED << target << "\e[m melee, ";
		std::cout << "causing " << melee << " points of damage ! +++" << std::endl;
	}
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (hp == 0)
		std::cout << BLU << "--- I am dead... How could I die more!? ---" << NC << std::endl;
	else if (hp <= amount)
	{
		std::cout << BLU << "--- My servos... are seizing... ---" << NC << std::endl;
		std::cout << "+++ " << name << " is getting damaged by " << hp << " health points! +++" << std::endl;
		hp = 0;
	}
	else
	{
		std::cout << BLU << "--- Oh my God, I 'm leaking! I think I' m leaking !Ahhhh, I 'm leaking! There's oil everywhere ! ---" << NC << std::endl;
		std::cout << "+++ " << name << " is getting damaged by " << amount << " health points! +++" << std::endl;
		hp -= amount;
	}
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (hp == max_hp)
		std::cout << BLU << "--- I am full HP! ---" << NC << std::endl;
	else
	{
		std::cout << BLU << "--- Good as new, I think. Am I leaking? ---" << NC << std::endl;
		std::cout << "+++ " << name << " is getting " << amount << " health points back! +++" << std::endl;
		hp += amount;
		if (hp > max_hp)
			hp = max_hp;
	}
}

void ScavTrap::challengeNewcomer(void)
{
	std::cout << R_BLU << "--- CHALLENGE NEWCOMER : ---" << NC << std::endl;
	std::cout << BLU << "";
	int r = rand() % 5;
	if (r == 1)
		std::cout << "--- Hey, Wanna dance !? ---" << std::endl;
	else if (r == 2)
		std::cout << "--- I'll stick an electrode up my back panel and call it paradise! ---" << std::endl;
	else if (r == 3)
		std::cout << "--- Get out of my scan range ---" << std::endl;
	else if (r == 4)
		std::cout << "--- MASTER !? ---" << std::endl;
	else
		std::cout << "--- I'll listen to you move your disgusting meat flaps ! ---" << std::endl;
	std::cout << "" << NC;
}
