/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 02:31:17 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/23 02:31:17 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

#define TITLE(str) std::cout << "\033[32m" << str << "\033[m" << std::endl

void identify_from_pointer(Base * p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "This object is of type A" << std::endl;
	if (dynamic_cast<B *>(p))
		std::cout << "This object is of type B" << std::endl;
	if (dynamic_cast<C *>(p))
		std::cout << "This object is of type C" << std::endl;
}

void identify_from_reference(Base & p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "This object is of type A" << std::endl;
	}
	catch(std::bad_cast) {}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "This object is of type B" << std::endl;
	}
	catch(std::bad_cast) {}
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "This object is of type C" << std::endl;
	}
	catch(std::bad_cast) {}	
}

int main()
{
	Base x;
	A a;
	B b;
	C c;

	TITLE("identify parent from pointer:");
	identify_from_pointer(&x);

	TITLE("identify each from pointer:");
	identify_from_pointer(&a);
	identify_from_pointer(&b);
	identify_from_pointer(&c);

	TITLE("identify from reference:");
	identify_from_reference(a);
	identify_from_reference(b);
	identify_from_reference(c);

	return 0;
}