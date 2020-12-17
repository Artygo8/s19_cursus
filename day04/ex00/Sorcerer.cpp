/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 12:00:01 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/04 12:00:01 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

// Contructors /////////////////////////////////////////////////////////////////

Sorcerer::Sorcerer(std::string name, std::string title) : name(name), title(title)
{
	std::cout << name << ", " << title << ", is born."<< std::endl;
}

Sorcerer::Sorcerer(const Sorcerer &source) : Sorcerer(source.name, source.title)
{
	std::cout << "Copy constructor for Sorcerer called" << std::endl;
}

Sorcerer::~Sorcerer()
{
	std::cout << name << ", " << title << ", is dead. Consequences will never be the same!" << std::endl;
}

Sorcerer& Sorcerer::operator = (const Sorcerer &source)
{
	std::cout << "Assignations operator for Sorcerer called" << std::endl;
	this->name = source.name;
	this->title = source.title;
	return *this;
}

// Utils ///////////////////////////////////////////////////////////////////////

std::string Sorcerer::getIntro() const//generic function
{
	return name + ", " + title;
}

std::ostream &operator<<(std::ostream &out, const Sorcerer &so)
{
	out << "I am " << so.getIntro() << " and I like ponies!" << std::endl;
	return out;
}

// Action //////////////////////////////////////////////////////////////////////

void Sorcerer::polymorph(Victim const &vi) const
{
	std::cout << name << " is transforming " << vi.getName() << "!" << std::endl;
	vi.getPolymorphed();
}
