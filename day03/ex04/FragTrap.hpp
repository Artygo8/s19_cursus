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
# include "ClapTrap.hpp"

using std::string;
using std::cout;

class FragTrap : virtual public ClapTrap
{
	public :
		// Constructors
		FragTrap();
		FragTrap(std::string name);
		FragTrap (const FragTrap &source);
		virtual ~FragTrap ();

		// Operators
		FragTrap &operator = (const FragTrap &source);

		// Utils
		void			rangedAttack(std::string const &target);
		void			meleeAttack(std::string const &target);
		void			takeDamage(unsigned int amount);
		void 			beRepaired(unsigned int amount);
		void 			vaulthunter_dot_exe(std::string const &target);
};

# endif
