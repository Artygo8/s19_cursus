/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:24:48 by agossuin          #+#    #+#             */
/*   Updated: 2020/05/03 14:04:33 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>


int main(int argc, char const *argv[])
{
	if (argc == 4)
	{
		std::string to_replace = argv[2];
		std::string line;
		std::string text;
		std::ifstream input_file(argv[1]);
		std::ofstream output_file((std::string)argv[1] + (std::string)".replace");

		while(getline(input_file, line))
			text += line + "\n";
		for (int i=0; i < text.size(); i++)
		{
			if (!(text.substr(i)).find(to_replace))
			{
				i += to_replace.size() - 1;
				output_file << argv[3];
			}
			else
				output_file << text[i];
		}
	}
	else
		std::cout << "Wrong Number of arguments\nUsage: ./replace FILENAME TO_REPLACE REPLACEMENT" << '\n';
	return 0;
}
