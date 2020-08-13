/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 16:31:54 by agossuin          #+#    #+#             */
/*   Updated: 2020/04/28 00:28:04 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

string	limit(string str, int l)
{
	if ((int)str.length() > l)
	{
		str.resize(l - 1);
		str.push_back('.');
	}
	return str;
}

void	Contact::infos(void)
{
	std::cout << std::left << std::setw(20) << "First Name: " << first_name << std::endl;
	std::cout << std::left << std::setw(20) << "Last Name: " << last_name << std::endl;
	std::cout << std::left << std::setw(20) << "Nickname: " << nickname << std::endl;
	std::cout << std::left << std::setw(20) << "Login: " << login << std::endl;
	std::cout << std::left << std::setw(20) << "Postal Adress: " << postal_address << std::endl;
	std::cout << std::left << std::setw(20) << "Email Adress: " << email_address << std::endl;
	std::cout << std::left << std::setw(20) << "Phone Number: " << phone_number << std::endl;
	std::cout << std::left << std::setw(20) << "Birthday Date: " << birthday_date << std::endl;
	std::cout << std::left << std::setw(20) << "Favorite Meal: " << favorite_meal << std::endl;
	std::cout << std::left << std::setw(20) << "Underwear Color: " << underwear_color << std::endl;
	std::cout << std::left << std::setw(20) << "Darkest Secret: " << darkest_secret << std::endl;
}

void	Contact::add(int total)
{
	index = total;
	std::cout << GRN << "Adding a contact" << CLEAN << std::endl;
	std::cout << "> Enter First Name: ";
	std::getline(std::cin, first_name);
	std::cout << "> Enter Last Name: ";
	std::getline(std::cin, last_name);
	std::cout << "> Enter Nickname: ";
	std::getline(std::cin, nickname);
	std::cout << "> Enter Login: ";
	std::getline(std::cin, login);
	std::cout << "> Enter Postal Adress: ";
	std::getline(std::cin, postal_address);
	std::cout << "> Enter Email Adress: ";
	std::getline(std::cin, email_address);
	std::cout << "> Enter Phone Number: ";
	std::getline(std::cin, phone_number);
	std::cout << "> Enter Birthday Date: ";
	std::getline(std::cin, birthday_date);
	std::cout << "> Enter Favorite Meal: ";
	std::getline(std::cin, favorite_meal);
	std::cout << "> Enter Underwear Color: ";
	std::getline(std::cin, underwear_color);
	std::cout << "> Enter Darkest Secret: ";
	std::getline(std::cin, darkest_secret);
}

void	Contact::show(void)
{
	std::cout << "|" << std::setw(10) << index + 1 << "|" << std::setw(10)
		<< limit(first_name, 10) << "|" << std::setw(10) << limit(last_name, 10)
		<< "|" << std::setw(10) << limit(login, 10) << "|\e[m" << std::endl;
}
