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

    Array( int n = 0 ) : array( new T[n] ), size( n ) {}
    
    ~Array() { delete[] this->array; }
    
    Array( Array const & source )
    {
        this->array = new T[source.size];
        this->size = source.size;
        
        for ( int i = 0; i < source.size; i++ )
        {
            this->array[i] = T( source.array[i] );
        }
    }
    
    Array & operator= ( Array const & source )
    {
        this->array = new T[source.size];
        this->size = source.size;

        for ( int i = 0; i < source.size; i++ )
        {
            this->array[i] = T( source.array[i] );
        }
        return *this;
    }

    T & operator[] ( int index )
    {
        if ( index >= this->size || index < 0 )
            throw ArrayOutOfBoundsException();
        return this->array[index];
    }

private:
    
    T * array;
    int size;

};

#endif
