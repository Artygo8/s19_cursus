/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 14:43:44 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/03 17:23:03 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>
# include <string>

using std::string;
using std::cout;


class Fixed
{

	private:
		int					value;
		static const int	f_nb = 8; //fractionnal number

	public:
		Fixed ();
		Fixed (const Fixed &source);
		Fixed (float val);
		Fixed (int val);
		~Fixed ();

		Fixed& operator = (const Fixed &source);

		int				getRawBits(void) const;
		void			setRawBits(int const raw);
		float			toFloat(void) const;
		int				toInt(void) const;

};

std::ostream &operator << (std::ostream &os, Fixed const &fixed);

# endif
