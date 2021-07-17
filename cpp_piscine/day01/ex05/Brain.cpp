/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 15:53:22 by agossuin          #+#    #+#             */
/*   Updated: 2020/04/28 23:07:44 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

std::string Brain::identify()
{
	return (address);
}


Brain::Brain()
{
	std::ostringstream oss;
	oss << (void const *)this;
	this->address = oss.str();;
	std::cout << "B+" << '\n';
}

Brain::~Brain()
{
	std::cout << "B-" << '\n';
}
