/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 13:25:05 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/24 13:25:05 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iostream>
# include <vector>
# include <set>
# include <list>
# include <algorithm>

template< typename T >
const int &easyfind (const T & array, int n)
{
    typename T::const_iterator it = std::find(array.begin(), array.end(), n);
    if (it == array.end())
        throw std::exception();
    return *it;
}

template< typename T >
void test_easyfind (const T & array, int n)
{
    try
    {
        std::cout << easyfind(array, n) << " found !" << std::endl;
    }
    catch (std::exception)
    {
        std::cerr << n << " not found !" << std::endl;
    }
}

#endif
