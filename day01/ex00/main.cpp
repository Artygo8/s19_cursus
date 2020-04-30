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
    Pony *AlbertLePoney = new Pony;

    AlbertLePoney->doSomeStuff();
    delete AlbertLePoney;
}

void ponyOnTheStack()
{
	Pony JeromeLePoney;

	JeromeLePoney.doSomeStuff();
}

int main()
{
	ponyOnTheHeap();
    ponyOnTheStack();
}
