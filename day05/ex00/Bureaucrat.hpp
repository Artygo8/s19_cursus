/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 20:59:03 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/15 20:59:03 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <exception>
# include <iostream>
# include <string>

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

# define TITLE(str) std::cout << R_BLU << str << NC << std::endl

using std::string;
using std::cout;


class Bureaucrat
{

	private:
		const std::string	name;
		int					grade;

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
		Bureaucrat (std::string name = "random", int grade = 150);
		Bureaucrat (const Bureaucrat &source);
		Bureaucrat &operator=(const Bureaucrat &source);
		virtual ~Bureaucrat ();

		// Utils
		std::string		getName() const;
		int				getGrade() const;

		void	incGrade();
		void	decGrade();

};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &obj);

# endif
