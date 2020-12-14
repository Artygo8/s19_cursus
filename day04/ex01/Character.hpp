/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 16:47:03 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/04 16:47:03 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <iostream>
# include <string>
# include "AWeapon.hpp" 
# include "Enemy.hpp" 
# define MAX_AP 40

using std::string;
using std::cout;


class Character
{

	private:
		std::string			name;
		int					ap;
		AWeapon				*wp;

	public:
		// Coplien
		Character (std::string const & name = "default Hero");
		Character (const Character &source);
		~Character ();
		Character &operator=(const Character &source);

		void				recoverAP();
		void				equip(AWeapon*);
		void				attack(Enemy*);
		std::string const	getName() const;
		int const			getAP() const;
		AWeapon				*getWeapon() const;

};

std::ostream &operator<<(std::ostream &out, Character const &obj);

# endif
