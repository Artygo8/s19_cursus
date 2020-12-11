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

# ifndef MY_COLORS
#  define MY_COLORS
#  define R_CYN "\e[46;30m"
#  define R_MGN "\e[45;30m"
#  define R_BLU "\e[44;30m"
#  define R_YLW "\e[43;30m"
#  define R_GRN "\e[42;30m"
#  define R_RED "\e[41;30m"
#  define CYN "\e[36m"
#  define MGN "\e[35m"
#  define BLU "\e[34m"
#  define YLW "\e[33m"
#  define GRN "\e[32m"
#  define RED "\e[31m"
#  define NC "\e[m"
# endif

using std::string;
using std::cout;


class AWeapon
{

	private:
		const std::string	&name;
		int					damage;
		int					apcost;

	public:
		// Coplien
		AWeapon(std::string const &name = "unknown weapon", int damage = 0, int apcost = 0);
		AWeapon (const AWeapon &source);
		virtual ~AWeapon ();
		AWeapon &operator=(const AWeapon &source);

		// Utils
		std::string		virtual getName() const;
		int				getAPCost() const;
		int				getDamage() const;

		virtual void	attack() const = 0;

};

std::ostream &operator<<(std::ostream &out, AWeapon const &obj);

# endif
