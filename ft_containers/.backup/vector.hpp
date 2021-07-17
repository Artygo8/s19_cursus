/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 12:00:01 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/28 12:00:01 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <iostream>
# include <string>

# define DEBUG(x) std::cout << x << std::endl << std::flush;


namespace ft
{
	template <typename T>
	class vector;
};


template<bool Condition, typename T = void>
struct enable_if {};


template<typename T>
struct enable_if<true, T>
{
	typedef T type;
};


template <typename T = int>
class ft::vector
{

private:


	//                 o     |    |              
	// .    ,,---.,---..,---.|---.|    ,---.,---.
	//  \  / ,---||    |,---||   ||    |---'`---.
	//   `'  `---^`    ``---^`---'`---'`---'`---'

	T*			array;
	size_t		_size;
	size_t		capacity;

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

		pointer	array;
		size_t	index;

		// CONSTRUCTORS
		iterator (pointer array = nullptr, size_t pos = -1)
		: array(array), index(pos) {}

		// OPERATORS
		friend bool		operator== (const iterator & lhs, const iterator & rhs)
		{
			return lhs.index == rhs.index;
		}

		friend bool		operator!= (const iterator & lhs, const iterator & rhs)
		{
			return lhs.index != rhs.index;
		}

		reference		operator* () const
		{
			return array[index];
		}

		pointer			operator-> () const
		{
			return &(array[index]);
		}

		iterator&		operator++ ()
		{
			index++;
			return *this;
		}

		iterator		operator++ (int)
		{
			iterator tmp = iterator(array, index++);
			return tmp;
		}

		iterator&		operator-- ()
		{
			index++;
			return *this;
		}

		iterator		operator-- (int)
		{
			iterator tmp = iterator(array, index++);
			return tmp;
		}

	};

	//                |    o          
	// ,---.,---.,---.|    .,---.,---.
	// |    |   ||   ||    ||---'|   |
	// `---'`---'|---'`---'``---'`   '
	//           |                    

	explicit vector ()
	: array(nullptr), _size(0), capacity(0) {}

	explicit vector (size_type n, const value_type& val = value_type())
	: array(new value_type[n]), _size(n), capacity(n * 2)
	{
		for (size_t i = 0; i < n; i++)
		{
			// DEBUG(5)
			addback(val);
			// DEBUG(6)
		}
	}

	template <class InputIterator>
	vector (InputIterator first, InputIterator last, typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type = 0)
	: array(nullptr), _size(0), capacity(0)
	{
		for (;first != last; first++)
		{
			// DEBUG(4)
			addback(*first);
			// DEBUG(3)
		}
	}

	vector (const vector& x)
	: array(new value_type[x.capacity]), _size(x._size), capacity(x.capacity)
	{
		for (size_t i = 0; i < _size; i++)
		{
			// DEBUG(1)
			array[i] = x.array[i];
			// DEBUG(2)
		}
	}

	~vector()
	{
		delete[] array;
	}

	void addback(const value_type& val)
	{
		if (_size >= capacity)
		{
			double_capacity();
		}
		array[_size++] = val;
	}

	iterator begin()
	{
		return iterator(array, 0);
	}

	iterator end()
	{
		return iterator(array, _size);
	}

	void double_capacity()
	{
		capacity *= 2;
		if (!capacity) capacity = 1;
		pointer future_array = new value_type[capacity];

		for (size_t i = 0; i < _size; i++)
		{
			future_array[i] = array[i];
		}
		if (array != nullptr) delete[] array;
		array = future_array;
	}

};

#endif
