/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 16:47:03 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/04 16:47:03 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWERFIST_HPP
# define POWERFIST_HPP
# include <iostream>
# include <string>
# include "AWeapon.hpp"

using std::string;
using std::cout;


class PowerFist : virtual public AWeapon
{

	private:
		std::string		name;

	public:
		// Coplien
		PowerFist ();
		PowerFist (const PowerFist &source);
		virtual ~PowerFist ();
		PowerFist &operator=(const PowerFist &source);

		virtual void	attack() const;

};

std::ostream &operator<<(std::ostream &out, PowerFist const &obj);

# endif
