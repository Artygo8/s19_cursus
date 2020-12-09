/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 18:49:08 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/03 18:49:08 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Contructors /////////////////////////////////////////////////////////////////

FragTrap::FragTrap(std::string name) :
hp(100),
max_hp(100),
energy(100),
max_energy(100),
lvl(1),
melee(30),
ranged(20),
armor(5)
{
	srand (time(NULL));
	std::cout << R_YLW << "    I'm Trap, Claptrap. Double oh... Trap. (constructor)" << NC << std::endl;
	this->name = name;
}

FragTrap::FragTrap(const FragTrap &source)
{
	std::cout << R_YLW << "    Let's get this party started! (copy)" << NC << std::endl;
	this->setAttributes(source);
}

FragTrap::~FragTrap()
{
	std::cout << R_YLW << "    I can see... the code... (destructor)    " << NC << std::endl;
}

// Operators ///////////////////////////////////////////////////////////////////

FragTrap &FragTrap::operator=(const FragTrap &source)
{
	std::cout << R_YLW << "*** Recompiling my combat code! (assignement) ***" << NC << std::endl;
	this->setAttributes(source);
	return *this;
}

// set-get ///////////////////////////////////////////////////////////////////////

void FragTrap::setAttributes(const FragTrap &copy) //generic function
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

std::string FragTrap::getName() //generic function
{
	return this->name;
}

// Actions /////////////////////////////////////////////////////////////////////

void FragTrap::rangedAttack(std::string const &target)
{
	if (max_hp == 0)
		std::cout << YLW << "--- I am dead... What can I do!? ---" << NC << std::endl;
	else
	{
		std::cout << YLW << "--- Get off my lawn! ---" << NC << std::endl;
		std::cout << "+++ FR4G - TP " << GRN << name << NC << " attacks " << RED << target << "\e[m at range, ";
		std::cout << "causing " << ranged << " points of damage ! +++" << std::endl;
	}
}

void FragTrap::meleeAttack(std::string const &target)
{
	if (hp == 0)
		std::cout << YLW << "--- I am dead... What can I do!? ---" << NC << std::endl;
	else
	{
		std::cout << YLW << "--- Ready for the PUNCHline?! ---" << NC << std::endl;
		std::cout << "+++ FR4G - TP " << GRN << name << "\e[m attacks " << RED << target << "\e[m melee, ";
		std::cout << "causing " << melee << " points of damage ! +++" << std::endl;
	}
}

void FragTrap::takeDamage(unsigned int amount)
{
	if (hp == 0)
		std::cout << YLW << "--- I am dead... How could I die more!? ---" << NC << std::endl;
	else if (hp <= amount)
	{
		std::cout << YLW << "--- My servos... are seizing... ---" << NC << std::endl;
		std::cout << "+++ " << name << " is getting damaged by " << hp << " health points! +++" << std::endl;
		hp = 0;
	}
	else
	{
		std::cout << YLW << "--- Oh my God, I 'm leaking! I think I' m leaking !Ahhhh, I 'm leaking! There's oil everywhere ! ---" << NC << std::endl;
		std::cout << "+++ " << name << " is getting damaged by " << amount << " health points! +++" << std::endl;
		hp -= amount;
	}
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (hp == max_hp)
		std::cout << YLW << "--- I am full HP! ---" << NC << std::endl;
	else
	{
		std::cout << YLW << "--- Good as new, I think. Am I leaking? ---" << NC << std::endl;
		std::cout << "+++ " << name << " is getting " << amount << " health points back! +++" << std::endl;
		hp += amount;
		if (hp > max_hp)
			hp = max_hp;
	}
}

void FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	std::cout << R_YLW << "--- VAULTHUNTER DOT EXE : ---" << NC << std::endl;
	if (energy < 25)
		std::cout << YLW << "--- Looks like I dont get the Power! ---" << NC << std::endl;
	else
	{
		std::cout << YLW << "";
		int r = rand() % 5;
		if (r == 1)
			std::cout << "--- Don't ask me where this ammo's coming from! ---" << std::endl;
		else if (r == 2)
			std::cout << "--- This was a reeeally bad idea! ---" << std::endl;
		else if (r == 3)
			std::cout << "--- Roses are red and/Violets are blue/Wait... how many syllables was that? ---" << std::endl;
		else if (r == 4)
			std::cout << "--- Ratattattattatta! Powpowpowpow! Powpowpowpow! Pew-pew, pew-pew-pewpew! ---" << std::endl;
		else
			std::cout << "--- Avast ye scurvy dogs! ---" << std::endl;
		std::cout << "" << NC;
		r = (rand() % melee) + 1;
		std::cout << "+++ FR4G - TP " << GRN << name << "\e[m attacks " << RED << target << "\e[m melee, ";
		std::cout << "causing " << r << " points of damage ! +++" << std::endl;
		energy -= 25;
	}
}
