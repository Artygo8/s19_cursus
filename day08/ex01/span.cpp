/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 18:20:17 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/26 18:20:17 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

// Coplien's form //////////////////////////////////////////////////////////////

Span::Span(int i) : size(i), filled(0), array(new int[i]) {}

Span::Span(const Span &source) : size(source.size), filled(source.filled), array(new int[source.size])
{
	for (unsigned int i = 0; i < source.filled; i++)
		array[i] = source.array[i];
}

Span& Span::operator = (const Span &source)
{
	delete[] this->array;
	size = source.size;
	filled = source.filled;
	array = new int[source.size];
	for (unsigned int i = 0; i < source.filled; i++)
		array[i] = source.array[i];
	return *this;
}

Span::~Span()
{
	delete[] array;
}

// others //////////////////////////////////////////////////////////////////////

void	Span::addNumber(int n)
{
	if (size == filled)
		throw ExceptionSpanOutOfBound();
	array[filled++] = n;
}

int	&Span::operator[](unsigned int index)
{
	if (index >= size)
		throw ExceptionSpanOutOfBound();
	return array[index];
}

unsigned int	Span::shortestSpan()
{
	if (filled < 2)
		throw ExceptionNotEnoughItems();

	Span copy(*this);
	std::sort (&copy.array[0], &copy.array[filled]);

	Span copy2(copy);
	std::transform (&copy.array[1], &copy.array[filled], &copy.array[0], &copy2.array[1], std::minus<int>());

	return *std::min_element(&copy2.array[1], &copy2.array[filled]);
}

unsigned int	Span::longestSpan()
{
	if (filled < 2)
		throw ExceptionNotEnoughItems();

	return (*std::max_element(&array[0], &array[filled]) - *std::min_element(&array[0], &array[filled]));
}
