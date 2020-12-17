/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UselessWeapon.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 16:47:03 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/04 16:47:03 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USELESSWEAPON_HPP
# define USELESSWEAPON_HPP
# include <iostream>
# include <string>
# include "AWeapon.hpp"

using std::string;
using std::cout;


class UselessWeapon : virtual public AWeapon
{

	private:
		std::string		name;

	public:
		// Constructors
		UselessWeapon ();
		UselessWeapon (const UselessWeapon &source);
		virtual ~UselessWeapon ();
		UselessWeapon &operator=(const UselessWeapon &source);

		virtual void	attack() const;

};

std::ostream &operator<<(std::ostream &out, UselessWeapon const &obj);

# endif
