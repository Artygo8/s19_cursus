/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 13:15:29 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/16 13:15:29 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include <iostream>
# include <string>

# include "Form.hpp"

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

# define TITLE(str) std::cout << R_RED << str << NC << std::endl

using std::string;
using std::cout;


class PresidentialPardonForm : public Form
{

	// PresidentialPardonForm (Grades requis : signature 25, execution 5).
	// Action : Nous annonce que <target> a été pardonnée par Zafod Beeblebrox.

	public:
		// Colpien's form
		PresidentialPardonForm (std::string cible = "default");
		PresidentialPardonForm (const PresidentialPardonForm &source);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &source);
		virtual ~PresidentialPardonForm ();

};

# endif
