/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 14:43:44 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/03 17:22:02 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//
// Constructors ////////////////////////////////////////////////////////////////
//

Fixed::Fixed()
{
	value = 0;
	std::cout << "Default constructor for Fixed called" << '\n';
}

Fixed::Fixed(const Fixed &source)
{
	this->value = source.getRawBits();
	std::cout << "Copy constructor for Fixed called" << '\n';
}

Fixed::Fixed(int val)
{
	this->value = (int)(pow(2, this->f_nb) * val);
	std::cout << "From int constructor for Fixed called" << '\n';
}

Fixed::Fixed(float val)
{
	this->value = roundf(pow(2, this->f_nb) * val);
	std::cout << "Copy constructor for Fixed called" << '\n';
}

Fixed::~Fixed()
{
	std::cout << "Destructor for Fixed called" << '\n';
}

//
// Operators////////////////////////////////////////////////////////////////////
//

Fixed& Fixed::operator = (const Fixed &source)
{
	std::cout << "Assignation operator for Fixed called" << '\n';
	this->value = source.getRawBits();
	return *this;
}

std::ostream &operator<<(std::ostream &out, Fixed const &fi)
{
    out << fi.toFloat();
    return (out);
}

//
// set-get RawBits /////////////////////////////////////////////////////////////
//

void		Fixed::setRawBits(int const raw) //generic function
{
	std::cout << "setRawBits for Fixed called" << '\n';
	this->value = raw;
}

int			Fixed::getRawBits(void) const //generic function
{
	std::cout << "getRawBits for  called" << '\n';
	return this->value;
}

//
// toInt-Float /////////////////////////////////////////////////////////////////
//

float		Fixed::toFloat(void) const
{
	return ((float)this->value / (float)pow(2, this->f_nb));
}

int			Fixed::toInt(void) const
{
	return ((int)roundf(this->value / pow(2, this->f_nb)));
}
