/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 16:47:03 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/04 16:47:03 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP
# include <iostream>
# include <string>

using std::string;
using std::cout;


class SuperMutant
{

	private:
		std::string		name;

	public:
		// Constructors
		SuperMutant ();
		SuperMutant (const SuperMutant &source);
		virtual ~SuperMutant ();

		// Operators
		SuperMutant &operator=(const SuperMutant &source);

		// Utils
		std::string		getName() const;
		void			setName(std::string name);

};

std::ostream &operator<<(std::ostream &out, SuperMutant const &obj);

# endif
