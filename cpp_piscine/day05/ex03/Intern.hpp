/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 20:59:03 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/15 20:59:03 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Intern_HPP
# define Intern_HPP
# include <exception>
# include <iostream>
# include <string>

# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

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

class Intern
{

	private:
		struct s_maker 
		{
			std::string	name;
			Form		*(*function)(std::string target); 
		};

	public:

		class UnrecognizedFormException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};

		// Colpien's form
		Intern ();
		Intern (const Intern &source);
		Intern &operator=(const Intern &source);
		virtual ~Intern ();

        Form    *makeForm(std::string name, std::string target);

};


# endif
