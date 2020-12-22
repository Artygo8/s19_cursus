/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 20:59:03 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/15 20:59:03 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Coplien's form //////////////////////////////////////////////////////////////

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &source) : name(source.name)
{
	this->grade = source.grade;
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat &source)
{
	this->grade = source.grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

// set-get ///////////////////////////////////////////////////////////////////////

std::string	Bureaucrat::getName() const
{
	return name;
}

int			Bureaucrat::getGrade() const
{
	return grade;
}

// stream //////////////////////////////////////////////////////////////////////

std::ostream &operator<<(std::ostream &out, Bureaucrat const &obj)
{
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return out;
}

// exceptions //////////////////////////////////////////////////////////////////

char const *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "The grade of the Bureaucrat is too low";
}

char const *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "The grade of the Bureaucrat is too high";
}

// others //////////////////////////////////////////////////////////////////////

void	Bureaucrat::incGrade()
{
	if (grade - 1 < 1)
		throw GradeTooHighException();
	grade--;
}

void	Bureaucrat::decGrade()
{
	if (grade + 1 > 150)
		throw GradeTooLowException();
	grade++;
}

void	Bureaucrat::signForm(Form &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << *this << " signs " << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << *this << " can't sign " << f << " because " << e.what() << std::endl;
	}
}
