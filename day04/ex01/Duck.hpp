/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Duck.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 16:47:03 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/04 16:47:03 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DUCK_HPP
# define DUCK_HPP
# include <iostream>
# include <string>
# include "Enemy.hpp"

using std::string;
using std::cout;

class Duck : public Enemy
{

	public:
		// Coplien
		Duck ();
		Duck (const Duck &source);
		virtual ~Duck ();
		Duck &operator=(const Duck &source);

};

# endif
