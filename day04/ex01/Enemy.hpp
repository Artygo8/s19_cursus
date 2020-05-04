/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 16:47:03 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/04 16:47:03 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP
# include <iostream>
# include <string>

using std::string;
using std::cout;


class Enemy
{

	private:
		std::string		name;

	public:
		// Constructors
		Enemy ();
		Enemy (const Enemy &source);
		virtual ~Enemy ();

		// Operators
		Enemy &operator=(const Enemy &source);

		// Utils
		std::string		getName() const;
		void			setName(std::string name);

};

std::ostream &operator<<(std::ostream &out, Enemy const &obj);

# endif
