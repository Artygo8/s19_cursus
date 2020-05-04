/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 16:47:03 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/04 16:47:03 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"

// Contructors /////////////////////////////////////////////////////////////////

PowerFist::PowerFist()
{
	std::cout << "Default constructor for PowerFist called" << std::endl;
}

PowerFist::PowerFist(const PowerFist &source)
{
	std::cout << "Copy constructor for PowerFist called" << std::endl;
}

PowerFist::~PowerFist()
{
	std::cout << "Destructor for PowerFist called" << std::endl;
}

// Operators ///////////////////////////////////////////////////////////////////

PowerFist& PowerFist::operator = (const PowerFist &source)
{
	std::cout << "Assignations operator for PowerFist called" << std::endl;
	return *this;
}

// set-get ///////////////////////////////////////////////////////////////////////

void		PowerFist::setName(std::string name) //generic function
{
	name = name;
}

std::string	PowerFist::getName() const//generic function
{
	return name;
}

// stream //////////////////////////////////////////////////////////////////////

std::ostream &operator<<(std::ostream &out, PowerFist const &obj)
{
	out << obj.getName();
	return out;
}

