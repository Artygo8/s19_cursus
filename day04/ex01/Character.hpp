/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 16:47:03 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/04 16:47:03 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <iostream>
# include <string>

using std::string;
using std::cout;


class Character
{

	private:
		std::string		name;

	public:
		// Constructors
		Character ();
		Character (const Character &source);
		virtual ~Character ();

		// Operators
		Character &operator=(const Character &source);

		// Utils
		std::string		getName() const;
		void			setName(std::string name);

};

std::ostream &operator<<(std::ostream &out, Character const &obj);

# endif
