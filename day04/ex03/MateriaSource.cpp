/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 00:00:23 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/15 00:00:23 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// Coplien's form //////////////////////////////////////////////////////////////

MateriaSource::MateriaSource()
{
	std::cout << "Default constructor for MateriaSource called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &source)
{
	this->name = source.name;
	std::cout << "Copy constructor for MateriaSource called" << std::endl;
}

MateriaSource& MateriaSource::operator = (const MateriaSource &source)
{
	this->name = source.name;
	std::cout << "Assignations operator for MateriaSource called" << std::endl;
	return *this;
}

MateriaSource::~MateriaSource()
{
	std::cout << "Destructor for MateriaSource called" << std::endl;
}

// set-get ///////////////////////////////////////////////////////////////////////

void		MateriaSource::setName(std::string name) //generic function
{
	this->name = name;
}

std::string	MateriaSource::getName() const//generic function
{
	return name;
}

// stream //////////////////////////////////////////////////////////////////////

std::ostream &operator<<(std::ostream &out, MateriaSource const &obj)
{
	out << obj.getName();
	return out;
}

// others //////////////////////////////////////////////////////////////////////

