/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 01:34:00 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/23 01:34:00 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

typedef	struct Data
{
	std::string s1;
	int n;
	std::string s2;
} 		Data;

void	show_data(Data *data)
{
	std::cout << "Pre-serialize: " << data->s1 << ", " << data->n << ", " << data->s2 << std::endl;
}

std::string	random_string()
{
    static char	res[9];

    for (int i = 0; i < 8; i++) 
        res[i] = "0123456789abcdefghijklmnopqrstuvwxyz"[rand() % 36];
    return static_cast<std::string>(res);
}

Data	*deserialize(void * raw)
{
	return reinterpret_cast<Data *>(raw);
}

void	*serialize(void)
{
	Data *raw = new Data;
	raw->s1 = random_string();;
	raw->n = rand();
	raw->s2 = random_string();;
	show_data(raw);
	return static_cast<void*>(raw);
}

int main()
{
    srand(time(NULL));

	void *raw = serialize();
	std::cout << "Serialized: " << raw << std::endl;
	// show_data(raw); // I CANT DO THAT

	Data *data = deserialize(raw);
	show_data(data);

	delete data;
	return 0;
}