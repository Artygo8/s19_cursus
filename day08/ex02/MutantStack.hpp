/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 12:51:45 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/27 12:51:45 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <iostream>
# include <string>
# include <stack>
# include <algorithm>

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

# define TITLE(str) std::cout << R_RED << str << NC << std::endl

using std::string;
using std::cout;

template < typename T >
class MutantStack : public std::stack < T >
{

	public:

		MutantStack() : std::stack < T > () {}

		MutantStack(const MutantStack &source) : std::stack < T > (source) {}

		MutantStack<T> operator=(const MutantStack &source)
		{
			std::stack<T>::operator =(source);
			return *this;
		}

		~MutantStack () {}

		class iterator
		{

			private:

				MutantStack<T>	&mstack;
				size_t			index;

			public:

				iterator( MutantStack<T> &mstack, size_t index ) : mstack(mstack), index(index) {}

				T & operator* () { return mstack.getElement(index); }

				void operator++() { index--; }

				void operator--() { index++; }

				bool operator==(const iterator& source)
				{
					return this->index == source.index && mstack == source.mstack;
				}

				bool operator!=(const iterator& source)
				{
					return !(*this == source);
				}

		};

		T & getElement(const size_t position)
		{
			MutantStack<T> revert_stack;

			for (size_t i = 1; i < position; i++)
			{
				revert_stack.push(this->top());
				this->pop();
			}
			T & result = this->top();
			while (!revert_stack.empty())
			{
				this->push(revert_stack.top());
				revert_stack.pop();
			}
			return result;
		}

		iterator begin()
		{
			return iterator( *this, this->size() );
		}

		iterator end()
		{
			return iterator( *this, 0 );
		}
};

#endif
