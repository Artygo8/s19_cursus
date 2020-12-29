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

namespace ft { template < class T > class list; };

//  .o88o.     .           oooo   o8o               .   
//  888 `"   .o8           `888   `"'             .o8   
// o888oo  .o888oo          888  oooo   .oooo.o .o888oo 
//  888      888            888  `888  d88(  "8   888   
//  888      888   o8o o8o  888   888  `"Y88b.    888   
//  888      888 . `"' `"'  888   888  o.  )88b   888 . 
// o888o     "888" o8o o8o o888o o888o 8""888P'   "888" 
//                 `"' `"'                              

template < typename T > class ft::list
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

	class node
	{
		public:
			T		&content;
			node	*previous;
			node	*next;
			
			node(T & content, node *previous, node *next) : content(content), previous(previous), next(next) {}
			node & operator =(const node & other)
			{
				*this = other;
				return *this;
			}

			// OPERATORS
			bool		operator== (const node & rhs) { return content == rhs.content; }
			bool		operator!= (const node & rhs) { return content != rhs.current; }
			T &			operator* () { return content; }
			void		operator++ ()
			{
				this->content = next->content;
				this->previous = next->previous;
				this->next = next->next;
			}
			void		operator++ (int)
			{
				this->content = next->content;
				this->previous = next->previous;
				this->next = next->next;
			}
			void		operator-- () { *this = *(previous); }
			void		operator-- (int) { *this = *(previous); }

			void add_back(node * new_node)
			{
				node *last;
				last = this;
				while (last->next)
					last = last->next;
				new_node->previous = last;
				last->next = new_node;
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

// o|                   |              
// .|--- ,---.,---.,---.|--- ,---.,---.
// ||    |---'|    ,---||    |   ||    
// ``---'`---'`    `---^`---'`---'`    

	class iterator
	{
		private:
			node *current;

		public:
			// CONSTRUCTORS
			iterator (node * current = nullptr) : current(current) {}
			iterator (const iterator & other) : current(other.current) {}
			
			// OPERATORS
			iterator	operator= (const iterator & other) { this->current = other.current; return *this;}
			bool		operator== (const iterator & rhs) { return this->current == rhs.current; }
			bool		operator!= (const iterator & rhs) { return this->current != rhs.current; }
			T			operator* ()
			{
				return *(*current);
			}
			void		operator++ () { ++(*current); }
			void		operator++ (int) { (*current)++; }
			void		operator-- () { --(*current); }
			void		operator-- (int) { (*current)--; }

	};

//                     |                   |              
// ,---.,---.,---.,---.|--- ,---..   .,---.|--- ,---.,---.
// |    |   ||   |`---.|    |    |   ||    |    |   ||    
// `---'`---'`   '`---'`---'`    `---'`---'`---'`---'`    

	list () : size(0), head(nullptr), tail(nullptr)
	{

	}

	// https://stackoverflow.com/questions/45847787/how-to-differentiate-fill-constructor-and-range-constructor-in-c11

	list (const size_t n, const T val) : size(n)
	{
		for (size_t i = 0; i < n; i++)
		{
			T tmp_val(val);
			node *new_node = new node(tmp_val, nullptr, nullptr);
			if (i == 0)
				head = new_node;
			else
				head->add_back(new_node);
			tail = new_node;
		}
	}

	template <typename InputIterator, typename = std::_RequireInputIter<InputIterator>>
	list (InputIterator first, InputIterator last)
	{
		size = 0;
		std::cout << "hey2" << std::endl;
		(void) first;
		(void) last;
	}

	list (const list & x)
	{
		(void) x;
	}

	iterator begin() { return iterator(head); }
	iterator end() { return iterator(tail); }

};

#endif
