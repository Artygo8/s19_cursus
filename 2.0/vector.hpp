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

#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP
# include "alloc.hpp"
# include <iostream>
# include <string>

namespace ft {

template < class T, class Alloc = ft::allocator<T> >
class vector {

public:

    // Member types
    typedef T                                           value_type;
    typedef Alloc                                       allocator_type;
    typedef typename allocator_type::reference	        reference;
    typedef typename allocator_type::const_reference    const_reference;
    typedef typename allocator_type::pointer            pointer;
    typedef typename allocator_type::const_pointer	    const_pointer;

    typedef std::ptrdiff_t                              difference_type;
    typedef size_t                                      size_type;

    // Only declarations
    // typedef T*                                          iterator;
    // typedef const T*                                    const_iterator;
    class iterator;
    typedef std::reverse_iterator<iterator>             reverse_iterator;
    // typedef std::reverse_iterator<const_iterator>       const_reverse_iterator;

private :
	T *array_;
	size_type reserved_size_;
	size_type size_;
    allocator_type alloc_;

    void grow() {
        if (reserved_size_ < 1) reserve(1);
        else reserve(reserved_size_ * 2);
    }

public:
    explicit vector (const allocator_type& alloc = allocator_type())
    : array_(new T[0]), reserved_size_(0), size_(0), alloc_(alloc) {}

    explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
    : array_(new T[n]), reserved_size_(n), size_(0), alloc_(alloc) {
        while (size_ < n) push_back(val);
    }

    template <class InputIterator>
    vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) 
    : array_(new T[0]), reserved_size_(0), size_(0), alloc_(alloc) {
        while (first != last) {
            push_back(*first++);
        }
    }

    vector (const vector& x) 
    : array_(new T[x.reserved_size_]), reserved_size_(x.reserved_size_), size_(x.size_), alloc_(x.alloc_) {
        for (size_t i = 0; i < size_; ++i)
            this->array_[i] = x.array_[i];
    }

    vector& operator= (const vector& x) {
        clear();
        this->array_ = new T[x.reserved_size_];
        this->reserved_size_ = x.reserved_size_;
        this->size_ = x.size_;
        this->alloc_ = x.alloc_;
        for (size_t i = 0; i < size_; ++i)
            this->array_[i] = x.array_[i];
        return *this;
    }

	~vector() { delete[] array_; }

    void push_back (const value_type& val)
    {
        if(size_ == reserved_size_) grow();
        array_[size_] = val;
        size_++;
    }

    void reserve(size_type n)
    {
        if(n > reserved_size_)
        {
            T *new_array( new T[n] );
            for(size_t i=0; i<size_; i++)
                new_array[i] = array_[i];
            delete[] array_;
            array_ = new_array;
            reserved_size_ = n;
        }
    }

    void resize (size_type n, value_type val = value_type()) {
        while (n > size_) push_back(val);
        size_ = n;
    }

    // ++ASSIGN
    template <class InputIterator>
    void assign (InputIterator first, InputIterator last) {
        for (size_t i = 0; first != last; ++i) {
            array_[i] = *first++;
            size_ = i + 1;
        }
    }

    void assign (size_type n, const value_type& val) {
        size_ = n;
        for (size_t i = 0; i < n; ++i) {
            array_[i] = val;
        }
    }
    // --ASSIGN

    // ++INSERT
    iterator insert (iterator position, const value_type& val) {
        insert(position, static_cast<size_type>(1), val);
        return position;
    }

    void insert (iterator position, size_type n, const value_type& val) {
        while (size_ + n >= reserved_size_) grow();
        for (iterator i = array_ + size_; i != position; i--) {
            i[n] = *i;
        }
        for (size_type i = 0; i < n; ++i) {
            position[i] = val;
        }
        size_ += n;
    }

    template <class InputIterator>
    void insert (iterator position, InputIterator first, InputIterator last) {
        size_t n = 0;
        for (iterator it = first; it != last; ++it) {
            n++;
        }
        while (size_ + n >= reserved_size_) grow();
        for (iterator i = array_ + size_; i != position; i--) {
            i[n] = *i;
        }
        for (size_type i = 0; i < n; ++i) {
            position[i] = *first++;
        }
        size_ += n;
    }
    // --INSERT

    // ONE_LINE
    bool empty() const { return size_ == 0; }
    void pop_back()                         { if (size_ > 0) --size_; }
    void clear()                            { delete[] array_; size_ = 0; reserved_size_ = 0; }
    size_type max_size()              const { return std::numeric_limits<unsigned long>::max() / sizeof(T); }
    size_type capacity()              const { return reserved_size_; }
    size_type size()                        { return size_; }
    iterator begin()                        { return array_; }
    iterator end()                          { return array_ + size_; }
    reverse_iterator rbegin()               { return reverse_iterator(end()); }
    reverse_iterator rend()                 { return reverse_iterator(begin()); }

    reference operator[] (size_type n)              { return array_[n]; }
    const_reference operator[] (size_type n) const  { return array_[n]; }
    reference at (size_type n)                      { return array_[n]; }
    const_reference at (size_type n) const          { return array_[n]; }
    reference front()                               { return array_[0]; }
    const_reference front() const                   { return array_[0]; }
    reference back()                                { return array_[size_ - 1]; }
    const_reference back() const                    { return array_[size_ - 1]; }

    class iterator {
        friend class vector<T>;
    public:
        typedef iterator                            iterator_type;
        typedef std::random_access_iterator_tag     iterator_category;
        typedef T                                   value_type;
        typedef T&                                  reference;
        typedef T*                                  pointer;

        typedef std::ptrdiff_t                      difference_type;
        typedef size_t                              size_type;

        iterator(T* p = 0) : current(p) {}
        iterator(const iterator& it) : current(it.current) {}
        ~iterator() {}

        iterator operator= (const iterator& it) { this->current = it.current; return *this; }

        T &operator*()                          { return *current; }
        T *operator->()                         { return current; }
        bool operator!=(const iterator &rhs)    { return current != rhs.current; }
        bool operator==(const iterator &rhs)    { return current == rhs.current; }
        iterator operator++(int)                { iterator tmp = iterator(current++); return tmp; }
        iterator operator--(int)                { iterator tmp = iterator(current--); return tmp; }
        iterator &operator++()                  { ++current; return *this; }
        iterator &operator--()                  { --current; return *this; }

        iterator operator+(int n)               { return current + n; }
        iterator operator-(int n)               { return current - n; }

        bool operator<(const iterator &rhs)     { return current < rhs.current; }
        bool operator>(const iterator &rhs)     { return current > rhs.current; }
        bool operator<=(const iterator &rhs)    { return current <= rhs.current; }
        bool operator>=(const iterator &rhs)    { return current >= rhs.current; }

        iterator operator+=(int n)              { current += n; return *this; }
        iterator operator-=(int n)              { current -= n; return *this; }

        T &operator[](int n)                    { return current[n]; }

    protected:
        T *current;
    };

}; // ft::vector

}; // ft::

#endif