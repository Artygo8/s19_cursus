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

		node(T data = 0, node *previous = nullptr, node *next = nullptr)
		: data(data), previous(previous), next(next) {}

		node(node & other)
		: data(other.data), previous(other.previous), next(other.next) {}

		node & operator= (const node & other)
		{
			data = other.data;
			previous = other.previous;
			next = other.next;
			return *this;
		}

		node *	clone()
		{
			node * _clone = new node(*this);
			return _clone;
		}
	};


	//                 o     |    |              
	// .    ,,---.,---..,---.|---.|    ,---.,---.
	//  \  / ,---||    |,---||   ||    |---'`---.
	//   `'  `---^`    ``---^`---'`---'`---'`---'

	size_t		_size;
	node		*head;
	node		*tail;


public:

	//                      
	//      |    o          
	// ,---.|    .,---.,---.
	// ,---||    |,---|`---.
	// `---^`---'``---^`---'
	//                      

	typedef T										value_type;
	typedef T&										reference;
	typedef T*										pointer;
	typedef const T&								const_reference;
	typedef const T*								const_pointer;
	typedef size_t									size_type;
	typedef ptrdiff_t								difference_type;


	// o|                   |              
	// .|--- ,---.,---.,---.|--- ,---.,---.
	// ||    |---'|    ,---||    |   ||    
	// ``---'`---'`    `---^`---'`---'`    

	
	struct iterator
	{
		typedef ptrdiff_t								difference_type;
		typedef std::bidirectional_iterator_tag			iterator_category;
		typedef T										value_type;
		typedef T&										reference;
		typedef T*										pointer;

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

		operator		node*()
		{
			return current;
		}

		reference		operator* () const
		{
			return current->data;
		}

		pointer			operator-> () const
		{
			return &(current->data);
		}

		iterator&		operator++ ()
		{
			if (!current) return *this;
			current = current->next;
			return *this;
		}

		iterator		operator++ (int)
		{
			if (!current) return *this;
			iterator tmp = iterator(current);
			current = current->next;
			return tmp;
		}

		iterator&		operator-- ()
		{
			if (!current) return *this;
			current = current->previous;
			return *this;
		}

		iterator		operator-- (int)
		{
			if (!current) return *this;
			iterator tmp = iterator(current);
			current = current->previous;
			return tmp;
		}

		node			get_content()
		{
			return *current;
		}

	};


	struct reverse_iterator
	{
		typedef ptrdiff_t								difference_type;
		typedef std::bidirectional_iterator_tag			iterator_category;
		typedef T										value_type;
		typedef T&										reference;
		typedef T*										pointer;

		node		*current;

		// CONSTRUCTORS
		reverse_iterator (node * current = nullptr)
		: current(current) {}

		// OPERATORS
		friend bool		operator== (const reverse_iterator & lhs, const reverse_iterator & rhs)
		{
			return lhs.current == rhs.current;
		}

		friend bool		operator!= (const reverse_iterator & lhs, const reverse_iterator & rhs)
		{
			return lhs.current != rhs.current;
		}

		operator		node*()
		{
			return current;
		}

		reference		operator* () const
		{
			return current->data;
		}

		pointer			operator-> () const
		{
			return &(current->data);
		}

		reverse_iterator&		operator++ ()
		{
			if (!current) return *this;
			current = current->previous;
			return *this;
		}

		reverse_iterator		operator++ (int)
		{
			if (!current) return *this;
			iterator tmp = iterator(current);
			current = current->previous;
			return tmp;
		}

		reverse_iterator&		operator-- ()
		{
			if (!current) return *this;
			current = current->next;
			return *this;
		}

		reverse_iterator		operator-- (int)
		{
			if (!current) return *this;
			iterator tmp = iterator(current);
			current = current->next;
			return tmp;
		}

		node			get_content()
		{
			return *current;
		}

	};


	//                |    o          
	// ,---.,---.,---.|    .,---.,---.
	// |    |   ||   ||    ||---'|   |
	// `---'`---'|---'`---'``---'`   '
	//           |                    

	explicit list ()
	: _size(0), head(nullptr), tail(nullptr) {}

	explicit list (size_type n, const value_type& val = value_type())
	: _size(n), head(nullptr), tail(nullptr)
	{
		assign(n, val);
	}

	template <typename InputIterator>
	list (InputIterator first, InputIterator last, typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type = 0)
	: _size(0), head(nullptr), tail(nullptr)
	{
		assign(first, last);
	}

	list (const list & x)
	: _size(0), head(nullptr), tail(nullptr)
	{
		node *tmp = x.head;
		while (tmp)
		{
			this->push_back(tmp->data);
			tmp = tmp->next;
		}
	}

	~list()
	{
		clear();
	}

	list& operator= (const list& x)
	{
		clear();
		node *tmp = x.head;
		while (tmp)
		{
			this->push_back(tmp->data);
			tmp = tmp->next;
		}
		return *this;
	}

	//                                                
	// |              o                              |
	// |---.,---.,---..,---.           ,---.,---.,---|
	// |   ||---'|   |||   |    ---    |---'|   ||   |
	// `---'`---'`---|``   '           `---'`   '`---'
	//           `---'                                

	iterator begin()
	{
		return iterator(head);
	}

	iterator end()
	{
		return iterator();
	}

	reverse_iterator rbegin()
	{
		return reverse_iterator(tail);
	}

	reverse_iterator rend()
	{
		return reverse_iterator();
	}

	//                                     
	//                          o|         
	// ,---.,---.,---.,---.,---..|--- ,   .
	// |    ,---||   |,---||    ||    |   |
	// `---'`---^|---'`---^`---'``---'`---|
	//           |                    `---'

	bool empty() const
	{
		return head == nullptr;
	}

	size_type size()
	{
		return _size;
	}

	size_type max_size()
	{
		return std::numeric_limits<size_type>::max() / sizeof(node);
	}

	//                                                                      
	//      |                        |                                      
	// ,---.|    ,---.,-.-.,---.,---.|---     ,---.,---.,---.,---.,---.,---.
	// |---'|    |---'| | ||---'|   ||        ,---||    |    |---'`---.`---.
	// `---'`---'`---'` ' '`---'`   '`---'    `---^`---'`---'`---'`---'`---'
	//                                                                      

	reference front()
	{
		return head->data;
	}

	const_reference front() const
	{
		return head->data;
	}

	reference back()
	{
		return tail->data;
	}

	const_reference back() const
	{
		return tail->data;
	}

	//                                      
	//               |o,---.o               
	// ,-.-.,---.,---|.|__. .,---.,---.,---.
	// | | ||   ||   |||    ||---'|    `---.
	// ` ' '`---'`---'``    ``---'`    `---'
	//                                      

	template <class InputIterator>
	void assign (InputIterator first, InputIterator last, typename std::enable_if<!std::is_integral<InputIterator>::value>::type * = nullptr)
	{
		clear();
		for (; first != last; first++)
		{
			this->push_back(*first);
		}
	}

	void assign (size_type n, const value_type& val)
	{
		clear();
		for (size_t i = 0; i < n; i++)
		{
			this->push_back(val);
		}
	}

	void push_front (const value_type& val)
	{
		if (!head)
		{
			head = tail = new node(val);
		}
		else
		{
			node * new_head = new node(val);
			new_head->next = head;
			head = new_head;
		}
	}

	void pop_front()
	{
		node *tmp = head->next;
		delete head;
		head = tmp;
		_size--;
		if (_size == 0) tail = nullptr;
	}

	void	push_back(const T & val)
	{
		if (!head || !tail)
		{
			head = tail = new node(val);
		}
		else
		{
			tail->next = new node(val);
			tail->next->previous = tail;
			tail = tail->next;
		}
		_size++;
	}

	void pop_back()
	{
		node *tmp = tail->previous;
		delete tail;
		tail = tmp;
		if (tail) tail->next = nullptr;
		_size--;
		if (_size == 0) head = nullptr;
	}

	iterator insert (iterator position, const value_type& val)
	{
		node		*current_node;
		node		*previous_tail;
		iterator	ret;

		current_node = static_cast<node*> (position);
		previous_tail = tail;
		tail = current_node->previous;
		push_back(val);
		ret = iterator(tail);
		tail->next = current_node;
		current_node->previous = tail;
		if (!previous_tail->next) tail = previous_tail;
		return (ret);
	}
	
	void insert (iterator position, size_type n, const value_type& val)
	{
		node	*pos_next;

		pos_next = static_cast<node*> (position);
		tail = pos_next->previous;
		for (size_type i = 0; i < n; i++)
		{
			push_back(val);
		}
		tail->next = pos_next;
		pos_next->previous = tail;
		while (tail->next) tail = tail->next;
	}

	template <class InputIterator>
	void insert (iterator position, InputIterator first, InputIterator last, typename std::enable_if<!std::is_integral<InputIterator>::value>::type * = nullptr)
	{
		node	*pos_next;

		pos_next = static_cast<node*> (position);
		tail = pos_next->previous;
		for (; first != last; ++first)
		{
			push_back(*first);
		}
		tail->next = pos_next;
		pos_next->previous = tail;
		while (tail->next) tail = tail->next;
	}

	iterator erase (iterator position)
	{
		node		*cur_node;
		iterator	ret;

		cur_node = static_cast<node*> (position);
		if (cur_node->next) cur_node->next->previous = cur_node->previous;
		else if (!cur_node->next) tail = cur_node->previous;
		if (cur_node->previous) cur_node->previous->next = cur_node->next;
		else if (!cur_node->previous) head = cur_node->next;
		ret = ++position;
		delete cur_node;
		_size--;
		return ret;
	}
	
	iterator erase (iterator first, iterator last)
	{
		while (first != last)
		{
			first = erase(first);
		}
		return (first);
	}

	void swap (list& x)
	{
		list tmp = *this;
		*this = x;
		x = tmp;
	}

	void resize (size_type n, value_type val = value_type())
	{
		while (n < _size)
		{
			pop_back();
		}
		while (_size < n)
		{
			push_back(val);
		}
	}

	void	clear()
	{
		node *tmp;
		while (head)
		{
			tmp = head;
			head = head->next;
			delete tmp;
		}
		head = tail = nullptr;
		_size = 0;
	}

	//                          |    o               
	// ,---.,---.,---.,---.,---.|--- .,---.,---.,---.
	// |   ||   ||---'|    ,---||    ||   ||   |`---.
	// `---'|---'`---'`    `---^`---'``---'`   '`---'
	//      |                                        

	void splice (iterator position, list& x)
	{
		node		*current_node;

		current_node = static_cast<node*> (position);
		_size += x._size;
		if (!current_node)
		{
			if (head)
			{
				tail->next = x.head;
				if (x.head) x.head->previous = tail;
				tail = x.tail;
			}
			else
			{
				head = x.head;
				tail = x.tail;
			}
		}
		else // we have a current_node
		{
			x.head->previous = current_node->previous;
			if (current_node->previous) current_node->previous->next = x.head;
			else head = x.head;
			x.tail->next = current_node;
			if (current_node) current_node->previous = x.tail;
			else tail = x.tail;
		}
		// forget x
		x.head = x.tail = nullptr;
		x._size = 0;
	}
	
	void splice (iterator position, list& x, iterator i)
	{
		node		*current_node;
		node		*new_node;

		// retrieve my node
		new_node = static_cast<node*> (i);
		if (!new_node) return ;
		if (new_node->previous) new_node->previous->next = new_node->next;
		else x.head = new_node->next;
		if (new_node->next) new_node->next->previous = new_node->previous;
		else x.tail = new_node->previous;
		(x._size)--;
		new_node->next = new_node->previous = nullptr;

		// new list
		_size++;
		current_node = static_cast<node*> (position);
		if (!current_node)
		{
			if (!head)
			{
				head = tail = new_node;
				head->next = head->previous = nullptr;
			}
			else
			{
				new_node->previous = tail;
				tail->next = new_node;
				tail = new_node;
			}
			return ;
		}
		if (current_node->previous) current_node->previous->next = new_node;
		else head = new_node;
		new_node->previous = current_node->previous;
		new_node->next = current_node;
		current_node->previous = new_node;
	}
	
	void splice (iterator position, list& x, iterator first, iterator last)
	{
		while (first != last)
		{
			splice (position, x, first++);
		}
	}

	void remove (const value_type& val)
	{
		for (iterator it = begin(); it != end();)
		{
			if (*it == val)
			{
				erase (it++);
			}
			else
			{
				it++;
			}
		}
	}

	template <class Predicate>
	void remove_if (Predicate pred)
	{
		for (iterator it = begin(); it != end();)
		{
			if (pred(*it))
			{
				erase(it++);
			}
			else
			{
				it++;
			}
		}
	}

	void unique()
	{
		node *last_node = nullptr;

		for (iterator it = begin(); it != end();)
		{
			node *cur_node = static_cast<node*> (it);
			if (last_node && cur_node->data == last_node->data)
			{
				erase(it++);
			}
			else
			{
				it++;
			}
			last_node = cur_node;
		}
	}

	template <class BinaryPredicate>
	void unique (BinaryPredicate binary_pred)
	{
		node *last_node = nullptr;

		for (iterator it = begin(); it != end();)
		{
			node *cur_node = static_cast<node*> (it);
			if (last_node && binary_pred(cur_node->data, last_node->data))
			{
				erase(it++);
			}
			else
			{
				it++;
			}
			last_node = cur_node;
		}
	}

	void merge (list& x)
	{
		for (iterator it = begin(); it != end();)
		{
			if (*it > x.front())
				splice(it, x, x.begin());
			else
				it++;
		}
		splice(end(), x);
	}

	template <class Compare>
	void merge (list& x, Compare comp)
	{
		for (iterator it = begin(); it != end();)
		{
			if (x.head && comp(x.front(), *it))
				splice(it, x, x.begin());
			else
				it++;
		}
		splice(end(), x);
	}

	void sort()
	{
		list tmp_list;

		swap(tmp_list);

		clear();
		while(tmp_list._size)
		{
			iterator smallest_it = tmp_list.begin();
			for (iterator it = tmp_list.begin(); it != tmp_list.end(); it++)
			{
				if (*smallest_it > *it) smallest_it = it;
			}
			this->push_back(*smallest_it);
			tmp_list.erase(smallest_it);
		}
	}

	template <class Compare>
	void sort (Compare comp)
	{
		list tmp_list;

		swap(tmp_list);
		clear();
		while(tmp_list._size)
		{
			iterator smallest_it = tmp_list.begin();
			for (iterator it = tmp_list.begin(); it != tmp_list.end(); it++)
			{
				if (!comp(*smallest_it, *it)) smallest_it = it;
			}
			this->push_back(*smallest_it);
			tmp_list.erase(smallest_it);
		}
	}

	void reverse()
	{
		node *new_head = tail;
		node *new_tail = head;
		
		while (head)
		{
			node *new_next = head->previous;

			head->previous = head->next;
			head->next = new_next;
			head = head->previous;
		}
		head = new_head;
		tail = new_tail;
	}

};

#endif

// https://stackoverflow.com/questions/45847787/how-to-differentiate-fill-constructor-and-range-constructor-in-c11
// #if __APPLE__
// 	template <typename InputIterator, typename std::enable_if<std::__is_cpp17_input_iterator<InputIterator>::value>::type*>
// #else
// 	template <typename InputIterator, typename = std::_RequireInputIter<InputIterator> >
// #endif

// https://www.fluentcpp.com/2018/05/15/make-sfinae-pretty-1-what-value-sfinae-brings-to-code/

// https://h-deb.clg.qc.ca/Sujets/TrucsScouts/Comprendre_enable_if.html