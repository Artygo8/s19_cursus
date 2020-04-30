/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 15:33:40 by agossuin          #+#    #+#             */
/*   Updated: 2020/04/28 15:44:21 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main() {
	std::string str = "HI THIS IS BRAIN";
	std::string ref = str;
	std::string *pointer = &str;

	std::cout << ref << '\n';
	std::cout << *pointer << '\n';
	return 0;
}
