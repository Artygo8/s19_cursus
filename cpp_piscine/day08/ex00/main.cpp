/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 13:25:05 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/24 13:25:05 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main ()
{
	int myints[]= { 19, 42, 27, 8, 51 };
	std::vector<int> v_array( myints, myints + 5 );
	std::set<int> s_array( myints, myints + 5 );
	std::list<int> l_array( myints, myints + 5 );

	std::cout << "my list contains { 19, 42, 27, 8, 51 }" << std::endl;

	std::cout << "test_easyfind each value with a copy of my list in a VECTOR, SET, LIST" << std::endl;

	test_easyfind(v_array, 19);
	test_easyfind(s_array, 19);
	test_easyfind(l_array, 19);

	test_easyfind(v_array, 24);
	test_easyfind(s_array, 24);
	test_easyfind(l_array, 24);

	test_easyfind(v_array, 42);
	test_easyfind(s_array, 42);
	test_easyfind(l_array, 42);

	test_easyfind(v_array, 51);
	test_easyfind(s_array, 51);
	test_easyfind(l_array, 51);
}