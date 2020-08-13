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

#include "contact.hpp"

void search(Contact phonebook[8], int total)
{
	string		str;
	int			count;

	std::cout << TITLE << "Searching through the phonebook" << CLEAN << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	for (int i = 0; i < total; ++i)
		phonebook[i].show();
	std::cout << BLU << "Which index would you like to access ?" << CLEAN << std::endl;
	std::getline(std::cin, str);
	std::stringstream(str) >> count;
	if (count <= total && count > 0)
		phonebook[count - 1].infos();
	else
		std::cout << RED << "This is not a valid search !" << CLEAN << std::endl;
}


int		main()
{
	Contact		phonebook[8];
	static int	total = 0;
	string		action;

	while (true)
	{
		std::cout << TITLE << "Enter a command (ADD, SEARCH, EXIT):" << CLEAN << std::endl;
		while (action.empty())
			std::getline(std::cin, action);
		if (action == "EXIT")
			return (0);
		else if (action == "ADD")
		{
			if (total >= 8)
				std::cout << RED << "You reached the maximum of contacts !" << CLEAN << std::endl;
			else
			{
				phonebook[total].add(total);
				total++;
			}
		}
		else if (action == "SEARCH")
			search(phonebook, total);
		else
			std::cout << RED << "This is not a valid input !" << CLEAN;
		action.clear();
	}
	return 0;
}
