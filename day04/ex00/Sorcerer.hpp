/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 12:00:01 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/04 12:00:01 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP
# include <iostream>
# include <string>
# include "Victim.hpp"

using std::string;
using std::cout;

class Sorcerer
{

	private:
		std::string name;
		std::string title;

	public:
		// Constructors
		Sorcerer(string name, string title);
		Sorcerer (const Sorcerer &source);
		virtual ~Sorcerer ();

		// Operators
		Sorcerer &operator = (const Sorcerer &source);

		// Utils
		std::string	getIntro() const;
		void		setName(std::string name);

		void		polymorph(Victim const &vi) const;
};

std::ostream		&operator<<(std::ostream &out, Sorcerer const &so);

# endif