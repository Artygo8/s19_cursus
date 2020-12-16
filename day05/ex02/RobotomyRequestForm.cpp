/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 13:15:29 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/16 13:15:29 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// Coplien's form //////////////////////////////////////////////////////////////

RobotomyRequestForm::RobotomyRequestForm(std::string cible) :
Form("RRF " + cible, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &source) :
Form(source)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator = (const RobotomyRequestForm &source)
{
	*this = source;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

// others //////////////////////////////////////////////////////////////////////

