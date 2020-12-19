/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 12:00:01 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/04 12:00:01 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"

// Contructors /////////////////////////////////////////////////////////////////

Peon::Peon(std::string name) : Victim(name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(const Peon &source) : Victim(source)
{
	std::cout << "Copy constructor for Peon called" << std::endl;
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
}

Peon& Peon::operator = (const Peon &source)
{
	std::cout << "Assignations operator for Peon called" << std::endl;
	this->name = source.name;
	return *this;
}

void Peon::getPolymorphed() const
{
	std::cout << name << " was just polymorphed into a pink pony!" << std::endl;
}
