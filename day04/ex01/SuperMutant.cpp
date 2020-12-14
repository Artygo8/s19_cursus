/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 16:47:03 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/04 16:47:03 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"

// Contructors /////////////////////////////////////////////////////////////////

SuperMutant::SuperMutant() : Enemy(170, "Super Mutant")
{
	// std::cout << "Default constructor for SuperMutant called" << std::endl;
	std::cout << "Gaaah. Break everything !" << std::endl;
}

SuperMutant::SuperMutant(const SuperMutant &source) : Enemy(source)
{
	// std::cout << "Copy constructor for SuperMutant called" << std::endl;
	std::cout << "Gaaah. Break everything !" << std::endl;
}

SuperMutant::~SuperMutant()
{
	// std::cout << "Destructor for SuperMutant called" << std::endl;
	std::cout << "Aaargh ..." << std::endl;
}

SuperMutant& SuperMutant::operator = (const SuperMutant &source)
{
	// std::cout << "Assignations operator for SuperMutant called" << std::endl;
	std::cout << "Gaaah. Break everything !" << std::endl;
	*this = source;
	return *this;
}

void 		SuperMutant::takeDamage(int amount)
{
	if (amount > 3)
		this->Enemy::takeDamage(amount - 3);
	else if (amount >= 0)
		this->Enemy::takeDamage(0);
	else
		this->Enemy::takeDamage(amount);
}
