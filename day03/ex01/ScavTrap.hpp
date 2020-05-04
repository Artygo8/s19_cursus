/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 01:32:53 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/04 01:32:53 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include <iostream>
# include <string>

using std::string;
using std::cout;

class ScavTrap
{

	private:
		std::string		name;

	public:
		// Constructors
		ScavTrap ();
		ScavTrap (const ScavTrap &source);
		virtual ~ScavTrap ();

		// Operators
		ScavTrap &operator = (const ScavTrap &source);

		// Utils
		std::string		getName();
		void			setName(std::string name);

};

# endif
