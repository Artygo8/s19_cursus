/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 15:49:16 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/22 15:49:16 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

int		is_nbr(char c)
{
	return (c >= '0' && c <= '9');
}

//      _             _     _      
//   __| | ___  _   _| |__ | | ___ 
//  / _` |/ _ \| | | | '_ \| |/ _ \
// | (_| | (_) | |_| | |_) | |  __/
//  \__,_|\___/ \__,_|_.__/|_|\___|
//                                 

void	special_cast_from_double(double d)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void	cast_from_double(double d)
{
	std::stringstream ss;

	if (static_cast<char>(d) < 32 || static_cast<char>(d) > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(d) << std::endl;
	std::cout << "int: " << static_cast<int>(d) << std::endl;
	ss << static_cast<float>(d);
	if (ss.str().find('.') < ss.str().length())
		std::cout << "float: " << ss.str() << "f" << std::endl;
	else
		std::cout << "float: " << ss.str() << ".0f" << std::endl;
	ss.str(std::string());
	ss << d;
	if (ss.str().find('.') < ss.str().length())
		std::cout << "double: " << ss.str() << std::endl;
	else
		std::cout << "double: " << ss.str() << ".0" << std::endl;
}

//   __ _             _   
//  / _| | ___   __ _| |_ 
// | |_| |/ _ \ / _` | __|
// |  _| | (_) | (_| | |_ 
// |_| |_|\___/ \__,_|\__|
//                        

void	special_cast_from_float(float f)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << static_cast<float>(f) << std::endl;
}

void	cast_from_float(float f)
{
	std::stringstream ss;

	if (static_cast<char>(f) < 32 || static_cast<char>(f) > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(f) << std::endl;
	std::cout << "int: " << static_cast<int>(f) << std::endl;
	ss << f;
	if (ss.str().find('.') < ss.str().length())
		std::cout << "float: " << ss.str() << "f" << std::endl;
	else
		std::cout << "float: " << ss.str() << ".0f" << std::endl;
	ss.str(std::string());
	ss << static_cast<double>(f);
	if (ss.str().find('.') < ss.str().length())
		std::cout << "double: " << ss.str() << std::endl;
	else
		std::cout << "double: " << ss.str() << ".0" << std::endl;}

//  _       _   
// (_)_ __ | |_ 
// | | '_ \| __|
// | | | | | |_ 
// |_|_| |_|\__|
//              

void	cast_from_int(int i)
{
	if (static_cast<char>(i) < 32 || static_cast<char>(i) > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(i) << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

//       _                
//   ___| |__   __ _ _ __ 
//  / __| '_ \ / _` | '__|
// | (__| | | | (_| | |   
//  \___|_| |_|\__,_|_|   
//                        

void	cast_from_char(char c)
{
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

//                  _       
//  _ __ ___   __ _(_)_ __  
// | '_ ` _ \ / _` | | '_ \\
// | | | | | | (_| | | | | |
// |_| |_| |_|\__,_|_|_| |_|
//                          

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cout << "Wrong number of arguments\n";
		return (0);
	}

	std::string content = argv[1];
	size_t i = 0;

	// Is it a char?
	if (!content[1] && !is_nbr(content[0]))
	{
		cast_from_char(content[0]);
		return 0;
	}
	
	// Is it an int?
	if (content[i] == '-') i++;
	
	while (is_nbr(content[i])) i++;
	
	if (content[i] == 0)
	{
		cast_from_int(std::stoi(content));
		return 0;
	}
	
	if (content[i] == '.') i++;
	
	// Is it still an int...?
	while (content[i] == '0') i++;
	
	if (content[i] == 0)
	{
		cast_from_int(std::stoi(content));
		return 0;
	}
	
	// Is it a double?
	while (is_nbr(content[i])) i++;
	
	if (content[i] == 0)
	{
		cast_from_double(std::stod(content));
		return 0;
	}

	if (content == "nan" || content == "inf" || content == "-inf")
	{
		special_cast_from_double(std::stod(content));
		return 0;
	}

	// Is it a float?
	if ((content[i] == 'f' && content[i + 1] == 0))
	{
		cast_from_float(std::stof(content));
		return 0;
	}

	if (content == "nanf" || content == "inff" || content == "-inff")
	{
		special_cast_from_float(std::stof(content));
		return 0;
	}
	
	// All impossible.
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;

	return 0;
}
