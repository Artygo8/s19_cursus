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

FragTrap::FragTrap() :
ClapTrap()
{
	std::cout << R_YLW << "    I'm Trap, Claptrap. Double oh... Trap. (default constructor)" << NC << std::endl;
}

FragTrap::FragTrap(std::string name) :
ClapTrap(100, 100, 100, 100, 1, name, 30, 20, 5)
{
	std::cout << R_YLW << "    I'm Trap, Claptrap. Double oh... Trap. (constructor)" << NC << std::endl;
}

FragTrap::FragTrap(const FragTrap &source) :
ClapTrap(source)
{
	std::cout << R_YLW << "    Let's get this party started! (copy)" << NC << std::endl;
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

// Actions /////////////////////////////////////////////////////////////////////

void FragTrap::rangedAttack(std::string const &target)
{
	std::cout << YLW << "--- Get off my lawn! ---" << NC << std::endl;
	ClapTrap::rangedAttack(target);
}

void FragTrap::meleeAttack(std::string const &target)
{
	std::cout << YLW << "--- Ready for the PUNCHline?! ---" << NC << std::endl;
	ClapTrap::meleeAttack(target);
}

void FragTrap::takeDamage(unsigned int amount)
{
	std::cout << YLW << "--- Oh my God, I 'm leaking! I think I' m leaking !Ahhhh, I 'm leaking! There's oil everywhere ! ---" << NC << std::endl;
	ClapTrap::takeDamage(amount);
}

void FragTrap::beRepaired(unsigned int amount)
{
	std::cout << YLW << "--- Good as new, I think. Am I leaking? ---" << NC << std::endl;
	ClapTrap::beRepaired(amount);
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
		std::cout << "+++ FR4G - TP " << GRN << this->toString() << "\e[m attacks " << RED << target << "\e[m melee, ";
		std::cout << "causing " << r << " points of damage ! +++" << std::endl;
		energy -= 25;
	}
}
