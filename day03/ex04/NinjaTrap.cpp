/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 18:49:08 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/03 18:49:08 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

// Contructors /////////////////////////////////////////////////////////////////

NinjaTrap::NinjaTrap(std::string name) :
ClapTrap(60, 60, 120, 120, 1, name, 60, 5, 0)
{
	std::cout << R_MGN << "    I'm Trap, Claptrap. Double oh... Trap. (constructor)" << NC << std::endl;
}

NinjaTrap::NinjaTrap(const NinjaTrap &source) :
ClapTrap(source)
{
	std::cout << R_MGN << "    Let's get this party started! (copy)" << NC << std::endl;
}

NinjaTrap::~NinjaTrap()
{
	std::cout << R_MGN << "    I can see... the code... (destructor)    " << NC << std::endl;
}

// Operators ///////////////////////////////////////////////////////////////////

NinjaTrap &NinjaTrap::operator=(const NinjaTrap &source)
{
	std::cout << R_MGN << "*** Recompiling my combat code! (assignement) ***" << NC << std::endl;
	this->setAttributes(source);
	return *this;
}

// Actions /////////////////////////////////////////////////////////////////////

void NinjaTrap::rangedAttack(std::string const &target)
{
	std::cout << MGN << "--- Get off my lawn! ---" << NC << std::endl;
	ClapTrap::rangedAttack(target);
}

void NinjaTrap::meleeAttack(std::string const &target)
{
	std::cout << MGN << "--- Ready for the PUNCHline?! ---" << NC << std::endl;
	ClapTrap::meleeAttack(target);
}

void NinjaTrap::takeDamage(unsigned int amount)
{
	std::cout << MGN << "--- Oh my God, I 'm leaking! I think I' m leaking !Ahhhh, I 'm leaking! There's oil everywhere ! ---" << NC << std::endl;
	ClapTrap::takeDamage(amount);
}

void NinjaTrap::beRepaired(unsigned int amount)
{
	std::cout << MGN << "--- Good as new, I think. Am I leaking? ---" << NC << std::endl;
	ClapTrap::beRepaired(amount);
}

void NinjaTrap::ninjaShoebox(ClapTrap &target)
{
	std::cout << R_MGN << "--- NINJA SHOEBOX : ---" << NC << std::endl;
	std::cout << MGN << "--- Looks like this is just a regular claptrap named " << target.getName() << " ---" << NC << std::endl;
}

void NinjaTrap::ninjaShoebox(FragTrap &target)
{
	std::cout << R_MGN << "--- NINJA SHOEBOX : ---" << NC << std::endl;
	std::cout << MGN << "--- I hate FragTraps, lets kick it ! ---" << NC << std::endl;
	this->meleeAttack(target.getName());
	target.takeDamage(this->melee);
}

void NinjaTrap::ninjaShoebox(ScavTrap &target)
{
	std::cout << R_MGN << "--- NINJA SHOEBOX : ---" << NC << std::endl;
	std::cout << MGN << "--- I know this ScavTrap ! Hello " << target.getName() << "! ---" << NC << std::endl;
}

void NinjaTrap::ninjaShoebox(NinjaTrap &target)
{
	std::cout << R_MGN << "--- NINJA SHOEBOX : ---" << NC << std::endl;
	std::cout << MGN << "--- Together, we are healthier ! ---" << NC << std::endl;
	this->beRepaired(50);
	target.beRepaired(50);
}
