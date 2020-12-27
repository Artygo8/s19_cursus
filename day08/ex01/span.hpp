/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 18:20:17 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/26 18:20:17 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <string>
# include <algorithm>
# include <functional>


# ifndef MY_COLORS
#  define MY_COLORS
#  define R_CYN "\e[46;30m"
#  define R_MGN "\e[45;30m"
#  define R_BLU "\e[44;30m"
#  define R_YLW "\e[43;30m"
#  define R_GRN "\e[42;30m"
#  define R_RED "\e[41;30m"
#  define CYN "\e[36m"
#  define MGN "\e[35m"
#  define BLU "\e[34m"
#  define YLW "\e[33m"
#  define GRN "\e[32m"
#  define RED "\e[31m"
#  define NC "\e[m"
# endif

# define TITLE(str) std::cout << R_MGN << str << NC << std::endl

using std::string;
using std::cout;


class Span
{
	class ExceptionSpanOutOfBound : public std::exception
	{
		const char* what() const throw()
		{
			return "index out of bounds.";
		}
	};

	class ExceptionNotEnoughItems : public std::exception
	{
		const char* what() const throw()
		{
			return "not enough items.";
		}
	};

	private:
		unsigned int	size;
		unsigned int	filled;
		int				*array;

	public:
		// Colpien's form
		Span (int i = 0);

		template <class InputIterator>
		Span (InputIterator first, InputIterator last)
		{
			InputIterator copy_first = first;
			unsigned int count = 0;

			while( copy_first++ != last )
				count++;

			this->filled = 0;
			this->size = count;
			this->array = new int[count];
			while(first!=last)
				this->addNumber(*first++);
		}

		Span (const Span &source);
		Span &operator=(const Span &source);
		virtual ~Span ();

		int &operator[](unsigned int index);
		void addNumber(int n);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		void			difference_with_previous(int n);

};

#endif
