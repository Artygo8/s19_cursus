/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 12:00:01 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/04 12:00:01 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP
# include <iostream>
# include <string>

using std::string;
using std::cout;

class Victim
{

	protected:
		std::string		name;

	public:
		// Constructors
		Victim(std::string name = "anonym");
		Victim (const Victim &source);
		virtual ~Victim ();

		// Operators
		Victim &operator = (const Victim &source);

		// Utils
		std::string		getName() const;
		std::string		getIntro() const;
		void			setName(std::string name);
		virtual void	getPolymorphed() const;

};

std::ostream &operator<<(std::ostream &out, Victim const &vi);

# endif
