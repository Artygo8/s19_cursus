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
# include "AMateria.hpp"

using std::string;
using std::cout;


class Cure : public AMateria
{

	public:
		// Colpien's form
		Cure ();
		Cure (const Cure &source);
		virtual Cure &operator = (const Cure &source);
		virtual ~Cure ();

		virtual Cure* clone() const;
		virtual void use(ICharacter& target);

};

# endif
