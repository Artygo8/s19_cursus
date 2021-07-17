/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 18:49:08 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/03 18:49:08 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include <iostream>
# include <string>
# include <cstdio>

# ifndef MY_COLORS
#  define MY_COLORS
#  define R_CYN "\e[46;30m"
#  define R_MGN "\e[45;30m"
#  define R_BLU "\e[44;30m"
#  define R_YLW "\e[43;30m"
#  define R_GRN "\e[42;30m"
#  define R_RED "\e[41;30m"
#  define CYN "\e[36m"
#  define MGN "\e[35m"
#  define BLU "\e[34m"
#  define YLW "\e[33m"
#  define GRN "\e[32m"
#  define RED "\e[31m"
#  define NC "\e[m"
# endif

using std::string;
using std::cout;

class FragTrap
{
	private:
		int hp;
		int max_hp;
		int energy;
		int max_energy;
		int lvl;
		std::string name;
		int melee;
		int ranged;
		int armor;

	public :
		// Constructors
		FragTrap();
		FragTrap(std::string name);
		FragTrap (const FragTrap &source);
		virtual ~FragTrap ();

		// Operators
		FragTrap &operator = (const FragTrap &source);

		// Utils
		std::string		getName();

		void			setAttributes(const FragTrap &copy);
		void			rangedAttack(std::string const &target);
		void			meleeAttack(std::string const &target);
		void			takeDamage(unsigned int amount);
		void 			beRepaired(unsigned int amount);
		void 			vaulthunter_dot_exe(std::string const &target);
};

# endif
