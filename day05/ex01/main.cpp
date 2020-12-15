/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 22:35:53 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/15 22:35:53 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://stackoverflow.com/questions/583076/c-c-changing-the-value-of-a-const#:~:text=A%20const%20variable%20can%20be,be%20modified%20through%20its%20pointer.

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(int argc, char const *argv[])
{
	for (int grade = 21 ; grade > 16 ; grade--)
	{
		Form a("28a", 19, 2);
		Bureaucrat john("John", grade);

		john.signForm(a);
	}

	return 0;
}