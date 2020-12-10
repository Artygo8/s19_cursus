/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warrior.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 12:00:01 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/04 12:00:01 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARRIOR_HPP
# define WARRIOR_HPP
# include <iostream>
# include <string>
# include "Victim.hpp"

using std::string;
using std::cout;

class Warrior : public Victim
{

	public:
		// Coplien
		Warrior(std::string name = "random warrior");
		~Warrior ();
		Warrior (const Warrior &source);
		Warrior &operator = (const Warrior &source);

		void getPolymorphed() const;

};

# endif
