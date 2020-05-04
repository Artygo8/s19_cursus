/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 01:41:47 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/04 01:41:47 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Contructors /////////////////////////////////////////////////////////////////

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor for ClapTrap called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &source)
{
	std::cout << "Copy constructor for ClapTrap called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor for ClapTrap called" << std::endl;
}

// Operators ///////////////////////////////////////////////////////////////////

ClapTrap& ClapTrap::operator = (const ClapTrap &source)
{
	std::cout << "Assignations operator for ClapTrap called" << std::endl;
	return *this;
}

// Utils ///////////////////////////////////////////////////////////////////////

void		ClapTrap::setName(std::string name) //generic function
{
	name = name;
}

std::string	ClapTrap::getName() //generic function
{
	return name;
}
