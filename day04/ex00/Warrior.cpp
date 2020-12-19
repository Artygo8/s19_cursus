/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warrior.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 12:00:01 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/04 12:00:01 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warrior.hpp"

// Contructors /////////////////////////////////////////////////////////////////

Warrior::Warrior(std::string name) : Victim(name)
{
	std::cout << "I AM READY TO FIGHT." << std::endl;
}

Warrior::Warrior(const Warrior &source) : Victim(source)
{
	std::cout << "Copy constructor for Warrior called" << std::endl;
	std::cout << "I AM READY TO FIGHT." << std::endl;
}

Warrior::~Warrior()
{
	std::cout << "I FAILED MY KINGDOM..." << std::endl;
}

Warrior& Warrior::operator = (const Warrior &source)
{
	std::cout << "Assignations operator for Warrior called" << std::endl;
	this->name = source.name;
	return *this;
}

void Warrior::getPolymorphed() const
{
	std::cout << name << " is changed into a little mouse!" << std::endl;
}
