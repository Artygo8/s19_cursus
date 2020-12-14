/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 20:30:35 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/14 20:30:35 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP
# include <iostream>
# include <string>
# include "ISpaceMarine.hpp"

using std::string;
using std::cout;


class AssaultTerminator : public ISpaceMarine
{

	public:
		// Colpien's form
		AssaultTerminator ();
		AssaultTerminator (const AssaultTerminator &source);
		AssaultTerminator &operator=(const AssaultTerminator &source);
		virtual ~AssaultTerminator ();

		ISpaceMarine* clone() const;
		void battleCry() const;
		void rangedAttack() const;
		void meleeAttack() const;

};

# endif
