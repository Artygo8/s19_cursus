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

# define DEBUG(x) std::cout << x << std::endl << std::flush;


namespace ft
{
	template <typename T>
	class list;
};


template<bool Condition, typename T = void>
struct enable_if {};


template<typename T>
struct enable_if<true, T>
{
	typedef T type;
};


template <typename T = int>
class ft::list
{

//                      o8o                            .             
//                      `"'                          .o8             
// oo.ooooo.  oooo d8b oooo  oooo    ooo  .oooo.   .o888oo  .ooooo.  
//  888' `88b `888""8P `888   `88.  .8'  `P  )88b    888   d88' `88b 
//  888   888  888      888    `88..8'    .oP"888    888   888ooo888 
//  888   888  888      888     `888'    d8(  888    888 . 888    .o 
//  888bod8P' d888b    o888o     `8'     `Y888""8o   "888" `Y8bod8P' 
//  888                                                              
// o888o                                                             

private:

	//               |     
	// ,---.,---.,---|,---.
	// |   ||   ||   ||---'
	// `   '`---'`---'`---'

	struct node
	{
		T		data;
		node	*previous;
		node	*next;

		node(T data, node *previous = nullptr, node *next = nullptr)
		: data(data), previous(previous), next(next) {}

		node(node & other)
		: data(other.data), previous(other.previous), next(other.next) {}

		node & operator =(const node & other)
		{
			data = other.data;
			previous = other.previous;
			next = other.next;
			return *this;
		}

		friend			std::ostream & operator << (std::ostream &out, const node & n)
		{
			out << "data : " << n.data;
		}

		void push_back(node * new_node)
		{
			node *last;
			last = this;
			while (last->next)
			{
				last = last->next;
			}
			new_node->next = nullptr;
			new_node->previous = last;
			last->next = new_node;
		}

		node * clone()
		{
			node * _clone = new node(*this);
			return _clone;
		}
	};


	//                 o     |    |              
	// .    ,,---.,---..,---.|---.|    ,---.,---.
	//  \  / ,---||    |,---||   ||    |---'`---.
	//   `'  `---^`    ``---^`---'`---'`---'`---'

	size_t		size;
	node		*head;
	node		*tail;

//                         .o8       oooo   o8o            
//                        "888       `888   `"'            
// oo.ooooo.  oooo  oooo   888oooo.   888  oooo   .ooooo.  
//  888' `88b `888  `888   d88' `88b  888  `888  d88' `"Y8 
//  888   888  888   888   888   888  888   888  888       
//  888   888  888   888   888   888  888   888  888   .o8 
//  888bod8P'  `V88V"V8P'  `Y8bod8P' o888o o888o `Y8bod8P' 
//  888                                                    
// o888o                                                   

public:

	//                      
	//      |    o          
	// ,---.|    .,---.,---.
	// ,---||    |,---|`---.
	// `---^`---'``---^`---'
	//                      

	typedef T						value_type;
	typedef value_type&				reference;
	typedef const value_type&		const_reference;
	typedef value_type*				pointer;
	typedef const value_type*		const_pointer;
	typedef size_t					size_type;
	typedef ptrdiff_t				difference_type;

	// o|                   |              
	// .|--- ,---.,---.,---.|--- ,---.,---.
	// ||    |---'|    ,---||    |   ||    
	// ``---'`---'`    `---^`---'`---'`    

	struct iterator
	{
		node		*current;

		// CONSTRUCTORS
		iterator (node * current = nullptr)
		: current(current) {}

		// OPERATORS
		friend bool		operator== (const iterator & lhs, const iterator & rhs)
		{
			return lhs.current == rhs.current;
		}

		friend bool		operator!= (const iterator & lhs, const iterator & rhs)
		{
			return lhs.current != rhs.current;
		}

		// debug
		friend			std::ostream & operator << (std::ostream &out, const iterator & n)
		{
			out << "my node : " << n.current;
		}

		T				operator* ()
		{
			return current->data;
		}

		iterator&		operator++ ()
		{
			current = current->next;
			return *this;
		}

		iterator		operator++ (int)
		{
			iterator tmp = iterator(current);
			current = current->next;
			return tmp;
		}

		iterator&		operator-- ()
		{
			current = current->previous;
			return *this;
		}

		iterator		operator-- (int)
		{
			iterator tmp = iterator(current);
			current = current->previous;
			return tmp;
		}

	};

	//                     |                   |              
	// ,---.,---.,---.,---.|--- ,---..   .,---.|--- ,---.,---.
	// |    |   ||   |`---.|    |    |   ||    |    |   ||    
	// `---'`---'`   '`---'`---'`    `---'`---'`---'`---'`    

	explicit list ()
	: size(0), head(nullptr), tail(nullptr) {}

	// https://www.fluentcpp.com/2018/05/15/make-sfinae-pretty-1-what-value-sfinae-brings-to-code/
	explicit list (size_type n, const value_type& val = value_type())
	: size(n), head(nullptr), tail(nullptr)
	{
		for (size_t i = 0; i < n; i++)
		{
			node *new_node = new node(val);
			if (!head)
				head = new_node;
			else
				head->push_back(new_node);
			tail = new_node;
		}
	}

	template <typename InputIterator>
	list (InputIterator first, InputIterator last, typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type = 0)
	: size(0), head(nullptr), tail(nullptr)
	{
		for (; first != last; first++)
		{
			node *new_node = new node(*first);
			if (!head)
				head = new_node;
			else
				head->push_back(new_node);
			tail = new_node;
			size++;
		}
	}

	list (const list & x)
	{
		(void) x;
	}

	iterator begin()
	{
		return iterator(head);
	}

	iterator end()
	{
		return iterator(nullptr);
	}

};

#endif




// https://stackoverflow.com/questions/45847787/how-to-differentiate-fill-constructor-and-range-constructor-in-c11
// #if __APPLE__
// 	template <typename InputIterator, typename std::enable_if<std::__is_cpp17_input_iterator<InputIterator>::value>::type*>
// #else
// 	template <typename InputIterator, typename = std::_RequireInputIter<InputIterator> >
// #endif