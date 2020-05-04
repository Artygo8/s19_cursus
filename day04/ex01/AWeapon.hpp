/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 16:47:03 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/04 16:47:03 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP
# include <iostream>
# include <string>

using std::string;
using std::cout;


class AWeapon
{

	private:
		const std::string	&name;
		int					apcost;
		int					damage;

	public:
		// Constructors
		AWeapon(std::string const &name, int apcost, int damage);
		AWeapon (const AWeapon &source);
		virtual ~AWeapon ();

		// Operators
		AWeapon &operator=(const AWeapon &source);

		// Utils
		std::string		getName() const;
		int				getAPCost() const;
		int				getDamage() const;
		void			setName(std::string name);

};

std::ostream &operator<<(std::ostream &out, AWeapon const &obj);

# endif
