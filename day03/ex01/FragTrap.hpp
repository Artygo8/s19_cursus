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
		FragTrap(std::string name);
		FragTrap (const FragTrap &source);
		virtual ~FragTrap ();

		// Operators
		FragTrap &operator = (const FragTrap &source);

		// Utils
		std::string		getName();

		FragTrap		setAttributes(const FragTrap &copy);
		void			rangedAttack(std::string const &target);
		void			meleeAttack(std::string const &target);
		void			takeDamage(unsigned int amount);
		void 			beRepaired(unsigned int amount);
		void 			vaulthunter_dot_exe(std::string const &target);
};

# endif
