/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 10:58:53 by agossuin          #+#    #+#             */
/*   Updated: 2020/04/27 11:47:30 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
	std::string longstr;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		longstr = argv[1];
	for (int i = 2; i < argc; ++i)
		longstr += (std::string)" " + argv[i];
	for (int i = 0; longstr[i]; ++i)
		if (longstr[i] <= 'z' && longstr[i] >= 'a')
			longstr[i] = longstr[i] - 32;
	std::cout << longstr << "\n";
	return 0;
}
