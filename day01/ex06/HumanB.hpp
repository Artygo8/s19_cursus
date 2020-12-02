/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 12:00:48 by agossuin          #+#    #+#             */
/*   Updated: 2020/04/29 12:28:19 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include <string>
# include <iostream>
# include "Weapon.hpp"

typedef std::string string;

class HumanB {

private:

	std::string		name;
	Weapon 			*wp;

public:

	HumanB(std::string n);
	~HumanB();
	void attack();
	void setWeapon(Weapon &wp);

};

#endif
