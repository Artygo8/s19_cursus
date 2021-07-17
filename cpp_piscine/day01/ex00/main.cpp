/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 10:39:40 by agossuin          #+#    #+#             */
/*   Updated: 2020/04/28 11:16:58 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void ponyOnTheHeap()
{
    Pony *AlbertLePoney = new Pony("Albert", "blue");

    AlbertLePoney->doSomeStuff();
    delete AlbertLePoney;
}

void ponyOnTheStack()
{
	Pony JeromeLePoney("Jerome", "purple");

	JeromeLePoney.doSomeStuff();
}

int main()
{
    std::cout << "We are in the main" << std::endl;
    std::cout << "Calling ponyOnTheHeap" << std::endl;
	ponyOnTheHeap();
    std::cout << "Calling ponyOnTheStack" << std::endl;
    ponyOnTheStack();
    std::cout << "End of the main" << std::endl;
}
