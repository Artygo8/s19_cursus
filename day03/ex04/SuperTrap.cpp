/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 18:49:08 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/03 18:49:08 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

// Contructors /////////////////////////////////////////////////////////////////

SuperTrap::SuperTrap() :
ClapTrap(), FragTrap(), NinjaTrap()
{
	std::cout << R_RED << "    I'm Trap, Claptrap. Double oh... Trap. (default constructor)" << NC << std::endl;
}

SuperTrap::SuperTrap(std::string name) :
ClapTrap(100, 100, 120, 120, 1, name, 60, 20, 5), FragTrap(name), NinjaTrap(name)
{
	std::cout << R_RED << "    I'm Trap, Claptrap. Double oh... Trap. (constructor)" << NC << std::endl;
}

SuperTrap::SuperTrap(const SuperTrap &source) :
ClapTrap(source), FragTrap(source), NinjaTrap(source)
{
	std::cout << R_RED << "    Let's get this party started! (copy)" << NC << std::endl;
}

SuperTrap::~SuperTrap()
{
	std::cout << R_RED << "    I can see... the code... (destructor)    " << NC << std::endl;
}

// Operators ///////////////////////////////////////////////////////////////////

SuperTrap &SuperTrap::operator=(const SuperTrap &source)
{
	std::cout << R_RED << "*** Recompiling my combat code! (assignement) ***" << NC << std::endl;
	this->setAttributes(source);
	return *this;
}

// Actions /////////////////////////////////////////////////////////////////////

void SuperTrap::rangedAttack(std::string const &target)
{
	FragTrap::rangedAttack(target);
}

void SuperTrap::meleeAttack(std::string const &target)
{
	NinjaTrap::meleeAttack(target);
}

void SuperTrap::takeDamage(unsigned int amount)
{
	std::cout << RED << "--- Oh my God, I 'm leaking! I think I' m leaking !Ahhhh, I 'm leaking! There's oil everywhere ! ---" << NC << std::endl;
	ClapTrap::takeDamage(amount);
}

void SuperTrap::beRepaired(unsigned int amount)
{
	std::cout << RED << "--- Good as new, I think. Am I leaking? ---" << NC << std::endl;
	ClapTrap::beRepaired(amount);
}
