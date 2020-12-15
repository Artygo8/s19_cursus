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
		Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		Bureaucrat::GradeTooHighException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &source) : name(source.name)
{
	this->grade = source.grade;
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat &source)
{
	*this = source;
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

// others //////////////////////////////////////////////////////////////////////

void	Bureaucrat::GradeTooLowException()
{
	throw "the grade of the Bureaucrat is too low";
}

void	Bureaucrat::GradeTooHighException()
{
	throw "the grade of the Bureaucrat is too high";
}

void	Bureaucrat::incGrade()
{
	if (grade - 1 < 1)
		this->GradeTooHighException();
	grade--;
}

void	Bureaucrat::decGrade()
{
	if (grade + 1 > 150)
		this->GradeTooLowException();
	grade++;
}

void	Bureaucrat::signForm(Form &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << *this << " signs " << f << std::endl;
	}
	catch (const char * m)
	{
		std::cout << *this << " can't sign " << f << " because " << m << std::endl;
	}
}
