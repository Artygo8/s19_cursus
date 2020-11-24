/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 10:54:49 by agossuin          #+#    #+#             */
/*   Updated: 2020/04/28 11:18:07 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony( string name, string color )
{
    setName(name);
    setColor(color);
    std::cout << "++ One pony is born ++\n";
}

Pony::~Pony() { std::cout << "-- One pony is dead --\n"; }

void Pony::doSomeStuff()
{
    std::cout << this->getName() << " is running "
    << YE << "* Cataclop, cataclop, cataclop *\n" << RC;
}


// set and get for NAME

void        Pony::setName( string new_value ) { this->name = new_value; }

std::string Pony::getName( void ) const { return this->name; }


// set and get for COLOR

void        Pony::setColor( string new_value ) { this->color = new_value; }

std::string Pony::getColor( void ) const { return this->color; }

