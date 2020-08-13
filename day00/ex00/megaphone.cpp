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
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc; ++i)
		for (int j = 0; argv[i][j]; ++j)
			std::cout << ((argv[i][j] <= 'z' && argv[i][j] >= 'a') ?
				(char)(argv[i][j] - 32) : argv[i][j]);
	std::cout << "\n";
	return 0;
}
