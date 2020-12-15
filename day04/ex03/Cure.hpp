/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 00:00:23 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/15 00:00:23 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP
# include <iostream>
# include <string>
#include "AMateria.hpp"

using std::string;
using std::cout;


class Cure : public AMateria
{

	public:
		// Colpien's form
		Cure ();
		Cure (const Cure &source);
		virtual Cure &operator=(const Cure &source);
		virtual ~Cure ();

		std::string const & getType() const; //Returns the materia type
		unsigned int getXP() const; //Returns the Materia's XP
		AMateria* clone() const;
		void use(ICharacter& target);

};

std::ostream &operator<<(std::ostream &out, Cure const &obj);

# endif
