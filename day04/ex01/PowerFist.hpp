/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 16:47:03 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/04 16:47:03 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWERFIST_HPP
# define POWERFIST_HPP
# include <iostream>
# include <string>

using std::string;
using std::cout;


class PowerFist
{

	private:
		std::string		name;

	public:
		// Constructors
		PowerFist ();
		PowerFist (const PowerFist &source);
		virtual ~PowerFist ();

		// Operators
		PowerFist &operator=(const PowerFist &source);

		// Utils
		std::string		getName() const;
		void			setName(std::string name);

};

std::ostream &operator<<(std::ostream &out, PowerFist const &obj);

# endif
