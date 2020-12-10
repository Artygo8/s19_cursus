/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 12:00:01 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/04 12:00:01 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// curl https://raw.githubusercontent.com/Artygo8/s19_cpp_piscine/master/generic_makefile/Makefile > Makefile

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include "Warrior.hpp"

int main(int argc, char const *argv[])
{
	Sorcerer so("Gandalph","Gray Mage");
	Victim vi("Rodolph");
	Peon pe("John");
	Warrior wa("Rambo");

	std::cout << so << vi << pe << wa;

	so.polymorph(vi);
	so.polymorph(pe);
	so.polymorph(wa);
	return 0;
}