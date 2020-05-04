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

SuperMutant::SuperMutant()
{
	std::cout << "Default constructor for SuperMutant called" << std::endl;
}

SuperMutant::SuperMutant(const SuperMutant &source)
{
	std::cout << "Copy constructor for SuperMutant called" << std::endl;
}

SuperMutant::~SuperMutant()
{
	std::cout << "Destructor for SuperMutant called" << std::endl;
}

// Operators ///////////////////////////////////////////////////////////////////

SuperMutant& SuperMutant::operator = (const SuperMutant &source)
{
	std::cout << "Assignations operator for SuperMutant called" << std::endl;
	return *this;
}

// set-get ///////////////////////////////////////////////////////////////////////

void		SuperMutant::setName(std::string name) //generic function
{
	name = name;
}

std::string	SuperMutant::getName() const//generic function
{
	return name;
}

// stream //////////////////////////////////////////////////////////////////////

std::ostream &operator<<(std::ostream &out, SuperMutant const &obj)
{
	out << obj.getName();
	return out;
}

