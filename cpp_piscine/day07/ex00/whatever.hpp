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
const T &	min( const T & x, const T & y ) {
	return ( x < y ? x : y );
}

template< typename T >
T &	min( T & x, T & y ) {
	return ( x < y ? x : y );
}

template< typename T >
const T &	max( const T & x, const T & y ) {
	return ( x > y ? x : y );
}

template< typename T >
T &	max( T & x, T & y ) {
	return ( x > y ? x : y );
}

# endif
