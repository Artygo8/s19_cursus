/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 13:15:29 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/16 13:15:29 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Coplien's form //////////////////////////////////////////////////////////////

ShrubberyCreationForm::ShrubberyCreationForm(std::string cible) :
Form("SCF " + cible, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &source) :
Form(source)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator = (const ShrubberyCreationForm &source)
{
	*this = source;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

// others //////////////////////////////////////////////////////////////////////

