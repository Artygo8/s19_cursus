/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 18:23:38 by agossuin          #+#    #+#             */
/*   Updated: 2020/04/28 22:00:08 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

std::string Human::identify()
{
	return getBrain().identify();
}

Brain &Human::getBrain()
{
	return (brain);
}

Human::Human()
{
	std::cout << "h+" << '\n';
}

Human::~Human()
{
	std::cout << "h-" << '\n';
}
