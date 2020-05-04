/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 16:47:03 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/04 16:47:03 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// Contructors /////////////////////////////////////////////////////////////////

Character::Character()
{
	std::cout << "Default constructor for Character called" << std::endl;
}

Character::Character(const Character &source)
{
	std::cout << "Copy constructor for Character called" << std::endl;
}

Character::~Character()
{
	std::cout << "Destructor for Character called" << std::endl;
}

// Operators ///////////////////////////////////////////////////////////////////

Character& Character::operator = (const Character &source)
{
	std::cout << "Assignations operator for Character called" << std::endl;
	return *this;
}

// set-get ///////////////////////////////////////////////////////////////////////

void		Character::setName(std::string name) //generic function
{
	name = name;
}

std::string	Character::getName() const//generic function
{
	return name;
}

// stream //////////////////////////////////////////////////////////////////////

std::ostream &operator<<(std::ostream &out, Character const &obj)
{
	out << obj.getName();
	return out;
}

