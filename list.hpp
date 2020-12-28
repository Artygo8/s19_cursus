/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 12:00:01 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/28 12:00:01 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP
# include <iostream>
# include <string>
# include <algorithm>
# include <list>
# include <memory>

std::list<int> l;

namespace ft
{
	template < class T >
	class list;
}

template < class T >
class ft::list
{
	private:

		struct node
		{
			T		data;
			node	*next;
			node	*previous;
		};

		size_t		size;
		node		*head;
		node		*tail;
	
	public:
		// (constructor)
		explicit list () : size(0), head(NULL), tail(NULL) {}

		explicit list (size_t n, const T & val = 0)
		{
			
		}

		template <class InputIterator>
		list (InputIterator first, InputIterator last)
		{
			(void) first;
			(void) last;
		}

		list (const list & x)
		{
			(void) x;
		}



};

#endif
