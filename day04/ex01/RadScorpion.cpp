/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 16:47:03 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/04 16:47:03 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RadScorpion.hpp"

// Contructors /////////////////////////////////////////////////////////////////

RadScorpion::RadScorpion()
{
	std::cout << "Default constructor for RadScorpion called" << std::endl;
}

RadScorpion::RadScorpion(const RadScorpion &source)
{
	std::cout << "Copy constructor for RadScorpion called" << std::endl;
}

RadScorpion::~RadScorpion()
{
	std::cout << "Destructor for RadScorpion called" << std::endl;
}

// Operators ///////////////////////////////////////////////////////////////////

RadScorpion& RadScorpion::operator = (const RadScorpion &source)
{
	std::cout << "Assignations operator for RadScorpion called" << std::endl;
	return *this;
}

// set-get ///////////////////////////////////////////////////////////////////////

void		RadScorpion::setName(std::string name) //generic function
{
	name = name;
}

std::string	RadScorpion::getName() const//generic function
{
	return name;
}

// stream //////////////////////////////////////////////////////////////////////

std::ostream &operator<<(std::ostream &out, RadScorpion const &obj)
{
	out << obj.getName();
	return out;
}

