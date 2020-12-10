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

ScavTrap::ScavTrap(std::string name) :
ClapTrap(100, 100, 50, 50, 1, name, 20, 15, 3)
{
	std::cout << R_BLU << "    I'm Trap, Claptrap. Double oh... Trap. (constructor)" << NC << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &source) :
ClapTrap(source)
{
	std::cout << R_BLU << "    Let's get this party started! (copy)" << NC << std::endl;
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

// Actions /////////////////////////////////////////////////////////////////////

void ScavTrap::rangedAttack(std::string const &target)
{
	std::cout << BLU << "--- Get off my lawn! ---" << NC << std::endl;
	ClapTrap::rangedAttack(target);
}

void ScavTrap::meleeAttack(std::string const &target)
{
	std::cout << BLU << "--- Ready for the PUNCHline?! ---" << NC << std::endl;
	ClapTrap::meleeAttack(target);
}

void ScavTrap::takeDamage(unsigned int amount)
{
	std::cout << BLU << "--- Oh my God, I 'm leaking! I think I' m leaking !Ahhhh, I 'm leaking! There's oil everywhere ! ---" << NC << std::endl;
	ClapTrap::takeDamage(amount);
}

void ScavTrap::beRepaired(unsigned int amount)
{
	std::cout << BLU << "--- Good as new, I think. Am I leaking? ---" << NC << std::endl;
	ClapTrap::beRepaired(amount);
}

void ScavTrap::challengeNewcomer(void)
{
	std::cout << BLU << "--- CHALLENGE NEWCOMER : ---" << NC << std::endl;
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
