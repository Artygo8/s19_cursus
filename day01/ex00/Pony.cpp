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

Pony::Pony(){std::cout << "++ One pony is born ++\n";}

Pony::~Pony(){std::cout << "-- One pony is dead --\n";}

void Pony::doSomeStuff() {std::cout << "* I LOOK AT THE PONY *\n";}
