/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 11:49:49 by agossuin          #+#    #+#             */
/*   Updated: 2020/04/28 00:20:06 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void search(Contact phonebook[8], int total)
{
	int			count;

	std::cout << "\n\e[4;32mSearching through the phonebook\e[m\n";
	std::cout << "\n\e[m|     index|first name| last name|  nickname|\e[m\n";
	for (int i = 0; i < total; ++i)
		phonebook[i].show();
	std::cout << "\n\e[96mTo which index would you like to access ?\e[m ";
	std::cin >> count;
	std::cout << std::endl;
	if (count <= total && count > 0)
		phonebook[count - 1].infos();
	else
		std::cout << "\nThis is not a valid input !\n";
}


int		main(int argc, char const *argv[])
{
	Contact		phonebook[8];
	static int	total = 0;
	string		action;

	while (1)
	{
		std::cout << "\n\e[1;4mEnter a command (ADD, SEARCH, EXIT):\e[m ";
		while (action.empty())
			std::getline(std::cin, action);
		if (action == "SEARCH")
			search(phonebook, total);
		else if (action == "EXIT")
			return (0);
		else if (action == "ADD")
		{
			if (total >= 8)
				std::cout << "\n\e[31mYou reached the maximum of contacts !\e[m\n";
			else
				phonebook[total].add(total);
				total++;
		}
		else
			std::cout << "\n\e[31mThis is not a valid input !\e[m\n";
		action = "";
	}
	return 0;
}
