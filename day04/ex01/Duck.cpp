/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Duck.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 16:47:03 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/04 16:47:03 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Duck.hpp"

// Coplien /////////////////////////////////////////////////////////////////////

Duck::Duck() : Enemy(1, "Duck")
{
	// std::cout << "Default constructor for Duck called" << std::endl;
	std::cout << "* coin coin *" << std::endl;
}

Duck::Duck(const Duck &source) : Enemy(source)
{
	// std::cout << "Copy constructor for Duck called" << std::endl;
	std::cout << "* coin coin *" << std::endl;
}

Duck::~Duck()
{
	// std::cout << "Destructor for Duck called" << std::endl;
	std::cout << "* Blublblblb... *" << std::endl;
}

Duck& Duck::operator = (const Duck &source)
{
	// std::cout << "Assignations operator for Duck called" << std::endl;
	std::cout << "* coin coin *" << std::endl;
	*this = source;
	return *this;
}

std::ostream &operator<<(std::ostream &out, Duck const &obj)
{
	out << obj.getType() << " has " << obj.getHP() << " hp" << std::endl;
	return (out);
}
