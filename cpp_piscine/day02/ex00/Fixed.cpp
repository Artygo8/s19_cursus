/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 14:43:44 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/03 15:36:01 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->value = 0;
	std::cout << "Default constructor for Fixed called" << '\n';
}

Fixed::Fixed(const Fixed &source)
{
	value = source.value;
	std::cout << "Copy constructor for Fixed called" << '\n';
}

Fixed& Fixed::operator = (const Fixed &source)
{
	std::cout << "Assignation operator for Fixed called" << '\n';
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor for Fixed called" << '\n';
}

void		Fixed::setRawBits(int const raw) //generic function
{
	std::cout << "setRawBits for Fixed called" << '\n';
	value = raw;
}

int			Fixed::getRawBits(void) const //generic function
{
	std::cout << "getRawBits for Fixed called" << '\n';
	return value;
}
