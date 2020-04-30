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

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include <string>
# include <iomanip>

typedef std::string	string;

string				format(string str);


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
