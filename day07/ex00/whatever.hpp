/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 22:45:12 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/23 22:45:12 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP
# include <iostream>
# include <string>

template< typename T >
void	swap( T & x, T & y ) {
	T tmp = x;
	x = y;
	y = tmp;
}

template< typename T >
T const &	min( T const & x, T const & y ) {
	return ( x < y ? x : y );
}

template< typename T >
T const &	max( T const & x, T const & y ) {
	return ( x > y ? x : y );
}

# endif
