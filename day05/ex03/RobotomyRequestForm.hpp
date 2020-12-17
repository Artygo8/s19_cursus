/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 13:15:29 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/16 13:15:29 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
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
#  define TITLE(str) std::cout << R_BLU << str << NC << std::endl
# endif


using std::string;
using std::cout;


class RobotomyRequestForm : public Form
{

	// RobotomyRequestForm (Grades requis : signature 72, execution 45).
	// Action : Fait des bruits de perceuses, et annonce que <target> a bien été
	// robotomizée. Le reste du temps, annonce son échec.

	public:
		// Colpien's form
		RobotomyRequestForm (std::string cible = "default");
		RobotomyRequestForm (const RobotomyRequestForm &source);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &source);
		virtual ~RobotomyRequestForm ();

		virtual void	execute (Bureaucrat const & executor) const;

};

# endif
