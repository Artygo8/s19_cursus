/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 11:51:27 by agossuin          #+#    #+#             */
/*   Updated: 2020/04/27 19:14:52 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
# include <string>
# include <iomanip>
# include <sstream>

# define TITLE "\e[1;4m"
# define CLEAN "\e[m"
# define BLU "\e[96m"
# define GRN "\e[33m"
# define RED "\e[31m"

typedef std::string	string;

class Contact {

public:

	void			add(int total);
	void			show(void);
	void			infos(void);

	// setters and getters
	void            setIndex( int new_value );
	int             getIndex( void ) const;
	void            setFirstName( string new_value );
	string          getFirstName( void ) const;
	void            setLastName( string new_value );
	string          getLastName( void ) const;
	void            setNickname( string new_value );
	string          getNickname( void ) const;
	void            setLogin( string new_value );
	string          getLogin( void ) const;
	void            setPostalAddress( string new_value );
	string          getPostalAddress( void ) const;
	void            setEmailAddress( string new_value );
	string          getEmailAddress( void ) const;
	void            setPhoneNumber( string new_value );
	string          getPhoneNumber( void ) const;
	void            setBirthdayDate( string new_value );
	string          getBirthdayDate( void ) const;
	void            setFavoriteMeal( string new_value );
	string          getFavoriteMeal( void ) const;
	void            setUnderwearColor( string new_value );
	string          getUnderwearColor( void ) const;
	void            setDarkestSecret( string new_value );
	string          getDarkestSecret( void ) const;

private:

	int				index;
	string			first_name;
	string			last_name;
	string			nickname;
	string			login;
	string			postal_address;
	string			email_address;
	string			phone_number;
	string			birthday_date;
	string			favorite_meal;
	string			underwear_color;
	string			darkest_secret;

};

#endif
