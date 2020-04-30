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

Brain *Human::identify()
{
	brain.identify();
}

Brain Human::getBrain()
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
