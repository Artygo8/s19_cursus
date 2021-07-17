/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 10:21:50 by agossuin          #+#    #+#             */
/*   Updated: 2020/04/29 11:06:23 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include <string>
# include <iostream>
# include "Weapon.hpp"

typedef std::string string;

class HumanA {

private:

	Weapon 			&wp;
	std::string		name;

public:

	HumanA(std::string n, Weapon &weapon);
	~HumanA();
	void attack();

};

#endif
