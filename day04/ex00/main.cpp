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

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"

int main(int argc, char const *argv[])
{
	Sorcerer so("Gandalph","Gray Mage");
	Victim vi("Rodolph");
	Peon pe("John");

	std::cout << so;
	std::cout << vi;
	std::cout << pe;

	so.polymorph(vi);
	so.polymorph(pe);
	return 0;
}