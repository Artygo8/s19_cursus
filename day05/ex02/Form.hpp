/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 22:35:53 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/15 22:35:53 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <string>

# include "Bureaucrat.hpp"

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


using std::string;
using std::cout;

class Bureaucrat;

class Form
{

	private:
		const std::string	name;
		bool				is_signed;
		const int			sign_grade;
		const int			exec_grade;

	public:

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};

		// Colpien's form
		Form (const std::string name = "paperwork", int sign_grade = 1, int exec_grade = 1);
		Form (const Form &source);
		Form &operator=(const Form &source);
		virtual ~Form ();

		// getters
		std::string		getName() const;
		bool			getIsSigned() const;
		int				getSignGrade() const;
		int				getExecGrade() const;

		void			beSigned(Bureaucrat &bu);

};

std::ostream &operator<<(std::ostream &out, Form const &obj);

# endif
