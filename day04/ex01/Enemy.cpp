/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 16:47:03 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/04 16:47:03 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

// Contructors /////////////////////////////////////////////////////////////////

Enemy::Enemy()
{
	std::cout << "Default constructor for Enemy called" << std::endl;
}

Enemy::Enemy(const Enemy &source)
{
	std::cout << "Copy constructor for Enemy called" << std::endl;
}

Enemy::~Enemy()
{
	std::cout << "Destructor for Enemy called" << std::endl;
}

// Operators ///////////////////////////////////////////////////////////////////

Enemy& Enemy::operator = (const Enemy &source)
{
	std::cout << "Assignations operator for Enemy called" << std::endl;
	return *this;
}

// set-get ///////////////////////////////////////////////////////////////////////

void		Enemy::setName(std::string name) //generic function
{
	name = name;
}

std::string	Enemy::getName() const//generic function
{
	return name;
}

// stream //////////////////////////////////////////////////////////////////////

std::ostream &operator<<(std::ostream &out, Enemy const &obj)
{
	out << obj.getName();
	return out;
}

