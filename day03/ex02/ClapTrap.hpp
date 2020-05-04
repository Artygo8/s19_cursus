/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 01:41:47 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/04 01:41:47 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>
# include <string>

using std::string;
using std::cout;

class ClapTrap
{

	private:
		std::string		name;

	public:
		// Constructors
		ClapTrap ();
		ClapTrap (const ClapTrap &source);
		virtual ~ClapTrap ();

		// Operators
		ClapTrap &operator = (const ClapTrap &source);

		// Utils
		std::string		getName();
		void			setName(std::string name);

};

# endif
