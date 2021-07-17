/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 23:50:16 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/23 23:50:16 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>
# include <string>
# include <exception>

template< typename T >
class Array
{

public:
	
	class ArrayOutOfBoundsException: public std::exception
	{
		virtual const char * what() const throw()
		{
			return "Array index Out Of Bounds.";
		}
	};

	Array( unsigned int n = 0 ) : array( new T[n] ), _size( n ) {}

	~Array() { delete[] this->array; }

	Array( const Array & source )
	{
		this->array = new T[source._size];
		this->_size = source._size;
		
		for ( unsigned int i = 0; i < source._size; i++ )
		{
			this->array[i] = T( source.array[i] );
		}
	}

	Array & operator= ( Array & source )
	{
		this->array = new T[source._size];
		this->_size = source._size;

		for ( unsigned int i = 0; i < source._size; i++ )
		{
			this->array[i] = T( source.array[i] );
		}
		return *this;
	}

	const Array & operator= ( const Array & source )
	{
		this->array = new T[source._size];
		this->_size = source._size;

		for ( unsigned int i = 0; i < source._size; i++ )
		{
			this->array[i] = T( source.array[i] );
		}
		return *this;
	}

	T & operator[] ( unsigned int index )
	{
		if ( index >= this->_size || index < 0 )
			throw ArrayOutOfBoundsException();
		return this->array[index];
	}

	const T & operator[] ( unsigned int index ) const
	{
		if ( index >= this->_size || index < 0 )
			throw ArrayOutOfBoundsException();
		return this->array[index];
	}

	unsigned int size()
	{
		return _size;
	}

private:
	
	T * array;
	unsigned int _size;

};

#endif
