/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 20:17:11 by agossuin          #+#    #+#             */
/*   Updated: 2020/04/29 12:28:04 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string>
# include <iostream>


class Weapon {

private:

	std::string	*ad_info;
	std::string	info;

public:
	Weapon (std::string info);
	~Weapon ();

	std::string	getType();
	void setType(std::string);
};

#endif
