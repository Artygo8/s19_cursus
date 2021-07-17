/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 00:00:23 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/15 00:00:23 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
# include <iostream>
# include <string>
# include "AMateria.hpp"

using std::string;
using std::cout;


class Ice : public AMateria
{

	public:
		// Colpien's form
		Ice ();
		Ice (const Ice &source);
		virtual Ice &operator=(const Ice &source);
		virtual ~Ice ();

		virtual Ice* clone() const;
		virtual void use(ICharacter& target);

};

# endif
