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
# include "AWeapon.hpp"

using std::string;
using std::cout;


class PlasmaRifle : virtual public AWeapon
{

	private:
		std::string		name;

	public:
		// Constructors
		PlasmaRifle ();
		PlasmaRifle (const PlasmaRifle &source);
		virtual ~PlasmaRifle ();
		PlasmaRifle &operator=(const PlasmaRifle &source);

		virtual void	attack() const;

};

std::ostream &operator<<(std::ostream &out, PlasmaRifle const &obj);

# endif
