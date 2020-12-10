/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 18:49:08 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/03 18:49:08 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Contructors /////////////////////////////////////////////////////////////////

ClapTrap::ClapTrap(int hp, int max_hp, int energy, int max_energy, int lvl, std::string name, int melee, int ranged, int armor) :
hp(hp),
max_hp(max_hp),
energy(energy),
max_energy(max_energy),
lvl(lvl),
melee(melee),
ranged(ranged),
armor(armor)
{
	srand (time(NULL));
	std::cout << R_GRN << "    I'm Trap, Claptrap. Double oh... Trap. (parent constructor)" << NC << std::endl;
	this->name = name;
}

ClapTrap::ClapTrap(const ClapTrap &source)
{
	std::cout << R_GRN << "    Let's get this party started! (copy)" << NC << std::endl;
	this->setAttributes(source);
}

ClapTrap::~ClapTrap()
{
	std::cout << R_GRN << "    I can see... the code... (destructor)    " << NC << std::endl;
}

// Operators ///////////////////////////////////////////////////////////////////

ClapTrap &ClapTrap::operator=(const ClapTrap &source)
{
	std::cout << R_GRN << "*** Recompiling my combat code! (assignement) ***" << NC << std::endl;
	this->setAttributes(source);
	return *this;
}

// set-get ///////////////////////////////////////////////////////////////////////

void ClapTrap::setAttributes(const ClapTrap &copy) //generic function
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

std::string ClapTrap::getName() //generic function
{
	return this->name;
}

// Actions /////////////////////////////////////////////////////////////////////

void ClapTrap::rangedAttack(std::string const &target)
{
	if (max_hp == 0)
		std::cout << "+++ CP - TP " << GRN << this->toString() << NC << " is dead... +++" << std::endl;
	else
	{
		std::cout << "+++ CP - TP " << GRN << this->toString() << NC << " attacks " << RED << target << "\e[m at range, ";
		std::cout << "causing " << ranged << " points of damage ! +++" << std::endl;
	}
}

void ClapTrap::meleeAttack(std::string const &target)
{
	if (hp == 0)
		std::cout << "+++ CP - TP " << GRN << this->toString() << NC << " is dead... +++" << std::endl;
	else
	{
		std::cout << "+++ FR4G - TP " << GRN << this->toString() << NC << " attacks " << RED << target << "\e[m melee, ";
		std::cout << "causing " << GRN << this->toString() << NC << " points of damage ! +++" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hp == 0)
		std::cout << "+++ CP - TP " << GRN << this->toString() << NC << " is dead... +++" << std::endl;
	else if (hp <= amount)
	{
		std::cout << "+++ " << GRN << this->toString() << NC << " is getting damaged by " << hp << " health points! +++" << std::endl;
		hp = 0;
	}
	else
	{
		std::cout << "+++ " << GRN << this->toString() << NC << " is getting damaged by " << amount << " health points! +++" << std::endl;
		hp -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hp != max_hp)
	{
		amount = (amount > max_hp - hp) ? max_hp - hp : amount;
		std::cout << "+++ " << GRN << this->toString() << NC << " is getting " << amount << " health points back! +++" << std::endl;
		hp += amount;
	}
	else
		std::cout << "+++ " << GRN << this->toString() << NC << " is full hp! +++" << std::endl;
}

std::string ClapTrap::toString(void)
{
	std::string str;
	str = this->name + "(" + std::to_string(this->hp) + "hp)";
	return (str);
}
