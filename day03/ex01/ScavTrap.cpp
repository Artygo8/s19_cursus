/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 01:32:53 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/04 01:32:53 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Contructors /////////////////////////////////////////////////////////////////

ScavTrap::ScavTrap()
{
	std::cout << "Default constructor for ScavTrap called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &source)
{
	std::cout << "Copy constructor for ScavTrap called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor for ScavTrap called" << std::endl;
}

// Operators ///////////////////////////////////////////////////////////////////

ScavTrap& ScavTrap::operator = (const ScavTrap &source)
{
	std::cout << "Assignations operator for ScavTrap called" << std::endl;
	return *this;
}

// Utils ///////////////////////////////////////////////////////////////////////

void		ScavTrap::setName(std::string name) //generic function
{
	name = name;
}

std::string	ScavTrap::getName() //generic function
{
	return name;
}
