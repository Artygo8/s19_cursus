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

	void			add(int total);
	void			show(void);
	void			infos(void);

private:

	string			underwear_color;
	string			darkest_secret;

};

#endif
