/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 16:47:03 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/04 16:47:03 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP
# include <iostream>
# include <string>

using std::string;
using std::cout;


class PlasmaRifle
{

	private:
		std::string		name;

	public:
		// Constructors
		PlasmaRifle ();
		PlasmaRifle (const PlasmaRifle &source);
		virtual ~PlasmaRifle ();

		// Operators
		PlasmaRifle &operator=(const PlasmaRifle &source);

		// Utils
		std::string		getName() const;
		void			setName(std::string name);

};

std::ostream &operator<<(std::ostream &out, PlasmaRifle const &obj);

# endif
