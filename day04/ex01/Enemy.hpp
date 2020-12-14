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
		std::string 		type;
		int 				hp;

	public:
		// Coplien
		Enemy (int hp = 100, std::string const & type = "unknown enemy");
		Enemy (const Enemy &source);
		virtual ~Enemy ();
		Enemy &operator=(const Enemy &source);

		// Utils
		std::string const getType() const;
		int getHP() const;

		virtual void takeDamage(int);

};

std::ostream &operator<<(std::ostream &out, Enemy const &obj);

# endif
