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

FragTrap::FragTrap(std::string name)
{
	std::cout << "\e[45m    I'm Trap, Claptrap. Double oh... Trap.    \e[m" << std::endl;
	this->name = name;
}

FragTrap::FragTrap(const FragTrap &source)
{
	std::cout << "\e[45m    Let's get this party started!    \e[m" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "\e[45m    I can see... the code... (destructor)    \e[m" << std::endl;
}

// Operators ///////////////////////////////////////////////////////////////////

FragTrap &FragTrap::operator=(const FragTrap &source)
{
	std::cout << "*** Recompiling my combat code! (assignation) ***" << std::endl;
	this->setAttributes(source);
	return *this;
}

// set-get ///////////////////////////////////////////////////////////////////////

FragTrap FragTrap::setAttributes(const FragTrap &copy) //generic function
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
	return *this;
}

std::string FragTrap::getName() //generic function
{
	return name;
}

// Actions /////////////////////////////////////////////////////////////////////

void FragTrap::rangedAttack(std::string const &target)
{
	if (max_hp == 0)
		std::cout << "\e[33m--- I am dead... What can I do!? ---\e[m" << std::endl;
	else
	{
		std::cout << "\e[33m--- Get off my lawn! ---\e[m" << std::endl;
		std::cout << "+++ FR4G - TP \e[32m" << name << "\e[m attacks \e[31m" << target << "\e[m at range, ";
		std::cout << "causing " << ranged << " points of damage ! +++" << std::endl;
	}
}

void FragTrap::meleeAttack(std::string const &target)
{
	if (hp == 0)
		std::cout << "\e[33m--- I am dead... What can I do!? ---\e[m" << std::endl;
	else
	{
		std::cout << "\e[33m--- Ready for the PUNCHline?! ---\e[m" << std::endl;
		std::cout << "+++ FR4G - TP \e[32m" << name << "\e[m attacks \e[31m" << target << "\e[m melee, ";
		std::cout << "causing " << melee << " points of damage ! +++" << std::endl;
	}
}

void FragTrap::takeDamage(unsigned int amount)
{
	if (hp == 0)
		std::cout << "\e[33m--- I am dead... How could I die more!? ---\e[m" << std::endl;
	else if (hp <= amount)
	{
		std::cout << "\e[33m--- My servos... are seizing... ---\e[m" << std::endl;
		std::cout << "+++ " << name << " is getting damaged by " << hp << " health points! +++" << std::endl;
		hp = 0;
	}
	else
	{
		std::cout << "\e[33m--- Oh my God, I 'm leaking! I think I' m leaking !Ahhhh, I 'm leaking! There's oil everywhere ! ---\e[m" << std::endl;
		std::cout << "+++ " << name << " is getting damaged by " << amount << " health points! +++" << std::endl;
		hp -= amount;
	}
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (hp == 100)
		std::cout << "\e[33m--- I am full HP! ---\e[m" << std::endl;
	else
	{
		std::cout << "\e[33m--- Good as new, I think. Am I leaking? ---\e[m" << std::endl;
		std::cout << "+++ " << name << " is getting " << amount << " health points back! +++" << std::endl;
		hp += amount;
		if (hp > amount)
			hp = 100;
	}
}

void FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	if (energy < 25)
		std::cout << "\e[33m--- Looks like I dont get the Power! ---\e[m" << std::endl;
	else
	{
		std::cout << "\e[33m";
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
		std::cout << "\e[m";
		r = (rand() % melee) + 1;
		std::cout << "+++ FR4G - TP \e[32m" << name << "\e[m attacks \e[31m" << target << "\e[m melee, ";
		std::cout << "causing " << r << " points of damage ! +++" << std::endl;
		energy -= 25;
	}
}
