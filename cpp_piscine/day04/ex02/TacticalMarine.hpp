/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 20:30:35 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/14 20:30:35 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP
# include <iostream>
# include <string>
# include "ISpaceMarine.hpp"

using std::string;
using std::cout;


class TacticalMarine : public ISpaceMarine
{

	public:
		// Colpien's form
		TacticalMarine ();
		TacticalMarine (const TacticalMarine &source);
		TacticalMarine &operator=(const TacticalMarine &source);
		virtual ~TacticalMarine ();

		ISpaceMarine* clone() const;
		void battleCry() const;
		void rangedAttack() const;
		void meleeAttack() const;

};

# endif
