/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 22:35:53 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/15 22:35:53 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Coplien's form //////////////////////////////////////////////////////////////


Form::Form (const std::string name, int sign_grade, int exec_grade, std::string target) :
name(name), target(target), is_signed(false), sign_grade(sign_grade), exec_grade(exec_grade)
{
	if (sign_grade > 150 || exec_grade > 150)
		throw GradeTooLowException();
	else if (sign_grade < 1 || exec_grade < 1)
		throw GradeTooHighException();
}

Form::Form(const Form &source) :
name(source.name), is_signed(source.is_signed), sign_grade(source.sign_grade), exec_grade(source.exec_grade)
{
}

Form& Form::operator = (const Form &source)
{
	this->is_signed = source.is_signed;
	return *this;
}

Form::~Form()
{
}

// set-get ///////////////////////////////////////////////////////////////////////

std::string	Form::getName() const
{
	return name;
}

std::string	Form::getTarget() const
{
	return target;
}

bool	Form::getIsSigned() const
{
	return is_signed;
}

int		Form::getSignGrade() const
{
	return sign_grade;
}

int		Form::getExecGrade() const
{
	return exec_grade;
}

// stream //////////////////////////////////////////////////////////////////////

std::ostream &operator<<(std::ostream &out, Form const &obj)
{
	out << "📄 \"" << obj.getName() <<"\" (sign grade=" << obj.getSignGrade()
	<<" / execution grade="<< obj.getExecGrade()
	<< ((obj.getIsSigned()) ? " / signed=✅)" : " / signed=❌)");
	return out;
}

// exceptions //////////////////////////////////////////////////////////////////

char const *Form::GradeTooLowException::what() const throw()
{
	return "The grade of the form is too low";
}

char const *Form::GradeTooHighException::what() const throw()
{
	return "The grade of the form is too high";
}

char const *Form::UnsignedFormException::what() const throw()
{
	return "The form is not signed";
}

// others //////////////////////////////////////////////////////////////////////

void	Form::beSigned(Bureaucrat &bu)
{
	if (sign_grade < bu.getGrade())
		throw GradeTooHighException();
	is_signed = true;
}

void	Form::execute (Bureaucrat const & executor) const
{
	if (!this->getIsSigned())
		throw UnsignedFormException();
	if (exec_grade < executor.getGrade())
		throw GradeTooHighException();
}
