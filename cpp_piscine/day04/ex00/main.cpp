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

#ifndef MY_COLORS
# define MY_COLORS
# define R_CYN "\e[46;30m"
# define R_MGN "\e[45;30m"
# define R_BLU "\e[44;30m"
# define R_YLW "\e[43;30m"
# define R_GRN "\e[42;30m"
# define R_RED "\e[41;30m"
# define CYN "\e[36m"
# define MGN "\e[35m"
# define BLU "\e[34m"
# define YLW "\e[33m"
# define GRN "\e[32m"
# define RED "\e[31m"
# define NC "\e[m"
# define TITLE_BLU(str) std::cout << R_BLU << str << NC << std::endl
# define TITLE_MGN(str) std::cout << R_MGN << str << NC << std::endl
#endif

int main()
{

	{
		TITLE_BLU("Constructors");

		Sorcerer so("Gandalph","Gray Mage");
		Victim vi("Rodolph");
		Peon pe("John");
		Warrior wa("Rambo");

		TITLE_BLU("Operator <<");
		std::cout << so << vi << pe << wa;

		TITLE_BLU("Polymorph");
		so.polymorph(vi);
		so.polymorph(pe);
		so.polymorph(wa);

		TITLE_BLU("Destructors");
	}

	{
		TITLE_MGN("Constructor Sorcerer");
		Sorcerer so("Gandalph","Gray Mage");
		TITLE_MGN("Copy Sorcerer");
		Sorcerer so_copy(so);

		TITLE_MGN("Constructor Victim");
		Victim vi("Rodolph");
		TITLE_MGN("Copy Victim");
		Victim vi_copy(vi);

		TITLE_MGN("Constructor Peon");
		Peon pe("John");
		TITLE_MGN("Copy Peon");
		Peon pe_copy(pe);

		TITLE_MGN("Destructors");
	}

	return 0;
}