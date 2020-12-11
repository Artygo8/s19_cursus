/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 12:00:01 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/04 12:00:01 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP
# include <iostream>
# include <string>
# include "Victim.hpp"

using std::string;
using std::cout;

class Peon : public Victim
{

	public:
		// Coplien
		Peon(std::string name = "random peon");
		virtual ~Peon ();
		Peon (const Peon &source);
		Peon &operator = (const Peon &source);

		void getPolymorphed() const;

};

# endif
