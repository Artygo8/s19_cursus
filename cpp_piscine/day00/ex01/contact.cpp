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
	std::cout << std::left << std::setw(20) << "First Name: " << getFirstName() << std::endl;
	std::cout << std::left << std::setw(20) << "Last Name: " << getLastName() << std::endl;
	std::cout << std::left << std::setw(20) << "Nickname: " << getNickname() << std::endl;
	std::cout << std::left << std::setw(20) << "Login: " << getLogin() << std::endl;
	std::cout << std::left << std::setw(20) << "Postal Adress: " << getPostalAddress() << std::endl;
	std::cout << std::left << std::setw(20) << "Email Adress: " << getEmailAddress() << std::endl;
	std::cout << std::left << std::setw(20) << "Phone Number: " << getPhoneNumber() << std::endl;
	std::cout << std::left << std::setw(20) << "Birthday Date: " << getBirthdayDate() << std::endl;
	std::cout << std::left << std::setw(20) << "Favorite Meal: " << getFavoriteMeal() << std::endl;
	std::cout << std::left << std::setw(20) << "Underwear Color: " << getUnderwearColor() << std::endl;
	std::cout << std::left << std::setw(20) << "Darkest Secret: " << getDarkestSecret() << std::endl;
}

void	Contact::add(int total)
{
	index = total;
	std::string name;
	std::cout << GRN << "Adding a contact" << CLEAN << std::endl;
	std::cout << "> Enter First Name: ";
	std::getline(std::cin, name);
	setFirstName(name);
	std::cout << "> Enter Last Name: ";
	std::getline(std::cin, name);
	setLastName(name);
	std::cout << "> Enter Nickname: ";
	std::getline(std::cin, name);
	setNickname(name);
	std::cout << "> Enter Login: ";
	std::getline(std::cin, name);
	setLogin(name);
	std::cout << "> Enter Postal Adress: ";
	std::getline(std::cin, name);
	setPostalAddress(name);
	std::cout << "> Enter Email Adress: ";
	std::getline(std::cin, name);
	setEmailAddress(name);
	std::cout << "> Enter Phone Number: ";
	std::getline(std::cin, name);
	setPhoneNumber(name);
	std::cout << "> Enter Birthday Date: ";
	std::getline(std::cin, name);
	setBirthdayDate(name);
	std::cout << "> Enter Favorite Meal: ";
	std::getline(std::cin, name);
	setFavoriteMeal(name);
	std::cout << "> Enter Underwear Color: ";
	std::getline(std::cin, name);
	setUnderwearColor(name);
	std::cout << "> Enter Darkest Secret: ";
	std::getline(std::cin, name);
	setDarkestSecret(name);
}

void	Contact::show(void)
{
	std::cout << "|" << std::setw(10) << index + 1 << "|" << std::setw(10)
		<< limit(first_name, 10) << "|" << std::setw(10) << limit(last_name, 10)
		<< "|" << std::setw(10) << limit(login, 10) << "|\e[m" << std::endl;
}


// get and set for INDEX

void        Contact::setIndex( int new_value ) { this->index = new_value; }

int         Contact::getIndex( void ) const { return this->index; }


// get and set for FIRST_NAME

void        Contact::setFirstName( string new_value ) { this->first_name = new_value; }

string      Contact::getFirstName( void ) const { return this->first_name; }


// get and set for LAST_NAME

void        Contact::setLastName( string new_value ) { this->last_name = new_value; }

string      Contact::getLastName( void ) const { return this->last_name; }


// get and set for NICKNAME

void        Contact::setNickname( string new_value ) { this->nickname = new_value; }

string      Contact::getNickname( void ) const { return this->nickname; }


// get and set for LOGIN

void        Contact::setLogin( string new_value ) { this->login = new_value; }

string      Contact::getLogin( void ) const { return this->login; }


// get and set for POSTAL_ADDRESS

void        Contact::setPostalAddress( string new_value ) { this->postal_address = new_value; }

string      Contact::getPostalAddress( void ) const { return this->postal_address; }


// get and set for EMAIL_ADDRESS

void        Contact::setEmailAddress( string new_value ) { this->email_address = new_value; }

string      Contact::getEmailAddress( void ) const { return this->email_address; }


// get and set for PHONE_NUMBER

void        Contact::setPhoneNumber( string new_value ) { this->phone_number = new_value; }

string      Contact::getPhoneNumber( void ) const { return this->phone_number; }


// get and set for BIRTHDAY_DATE

void        Contact::setBirthdayDate( string new_value ) { this->birthday_date = new_value; }

string      Contact::getBirthdayDate( void ) const { return this->birthday_date; }


// get and set for FAVORITE_MEAL

void        Contact::setFavoriteMeal( string new_value ) { this->favorite_meal = new_value; }

string      Contact::getFavoriteMeal( void ) const { return this->favorite_meal; }


// get and set for UNDERWEAR_COLOR

void        Contact::setUnderwearColor( string new_value ) { this->underwear_color = new_value; }

string      Contact::getUnderwearColor( void ) const { return this->underwear_color; }


// get and set for DARKEST_SECRET

void        Contact::setDarkestSecret( string new_value ) { this->darkest_secret = new_value; }

string      Contact::getDarkestSecret( void ) const { return this->darkest_secret; }
