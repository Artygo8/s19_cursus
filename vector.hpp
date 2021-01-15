/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 12:00:01 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/28 12:00:01 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <iostream>
# include <string>

# define DEBUG(x) std::cout << x << std::endl << std::flush;


namespace ft
{
	template <typename T>
	class vector;
};


template<bool Condition, typename T = void>
struct enable_if {};


template<typename T>
struct enable_if<true, T>
{
	typedef T type;
};


template <typename T = int>
class ft::vector
{
	
};

#endif
