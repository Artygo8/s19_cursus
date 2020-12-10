/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 18:49:08 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/03 18:49:08 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SuperTrap_HPP
# define SuperTrap_HPP
# include <iostream>
# include <string>
# include <cstdio>
# include "FragTrap.hpp"
# include "NinjaTrap.hpp"

using std::string;
using std::cout;

class SuperTrap : public FragTrap, public NinjaTrap
{
	public :
		// Constructors
		SuperTrap(std::string name);
		SuperTrap (const SuperTrap &source);
		virtual ~SuperTrap ();

		// Operators
		SuperTrap &operator = (const SuperTrap &source);

		// Utils
		void			rangedAttack(std::string const &target);
		void			meleeAttack(std::string const &target);
		void			takeDamage(unsigned int amount);
		void 			beRepaired(unsigned int amount);
};

# endif
