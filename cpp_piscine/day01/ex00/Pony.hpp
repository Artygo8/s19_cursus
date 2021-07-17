/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 10:50:16 by agossuin          #+#    #+#             */
/*   Updated: 2020/04/28 11:24:02 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP
# include <iostream>
# include <string>
# include <iomanip>

# define YE "\033[33m"
# define RC "\033[0m"


typedef std::string string;

class Pony {

public:

	Pony(std::string name, std::string color);
	~Pony();
	void		doSomeStuff();

	// setters and getters
	void            setName( std::string new_value );
	std::string     getName( void ) const;
	void            setColor( std::string new_value );
	std::string     getColor( void ) const;

private:

	std::string name;
	std::string color;

};

#endif
