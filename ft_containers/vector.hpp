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
    class iterator;
    class const_iterator;
    typedef std::reverse_iterator<iterator>             reverse_iterator;
    typedef std::reverse_iterator<const_iterator>       const_reverse_iterator;

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
        delete[] array_;
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
            for(size_t i=0; i<size_; i++) new_array[i] = array_[i];
            delete[] array_;
            array_ = new_array;
            reserved_size_ = n;
        }
    }

    void resize (size_type n, value_type val = value_type()) {
        while (n > size_) push_back(val);
        size_ = n;
    }

    void swap (vector& x) {
        {
            T* tmp = x.array_;
            x.array_ = array_;
            array_ = tmp;
        }
        {
            size_t tmp = x.size_;
            x.size_ = size_;
            size_ = tmp;
            tmp = x.reserved_size_;
            x.reserved_size_ = reserved_size_;
            reserved_size_ = tmp;
        }
        {
            allocator_type tmp = x.alloc_;
            x.alloc_ = alloc_;
            alloc_ = tmp;
        }
    }

    // ++ASSIGN
    template <class InputIterator>
    void assign (InputIterator first, InputIterator last) {
        size_ = 0;
        while (first != last)
            push_back(*first++);
    }

    void assign (size_type n, const value_type& val) {
        size_ = n;
        while (size_ >= reserved_size_) grow();
        for (size_t i = 0; i < n; ++i) {
            array_[i] = val;
        }
    }
    // --ASSIGN

    // ++INSERT
private:
    size_type get_index(iterator position) {
        size_t index = 0;
        while (iterator(array_ + index) < position)
            ++index; // we need to do that because when we grow, we lose the iterator.
        return index;
    }

    size_type get_quantity(iterator first, iterator last) {
        size_t n = 0;
        for (iterator it = first; it < last; ++it)
            n++;
        return n;
    }

public:
    iterator insert (iterator position, const value_type& val) {
        insert(position, static_cast<size_type>(1), val);
        return position;
    }

    void insert (iterator position, size_type n, const value_type& val) {
        size_t pos_index = 0;
        while (iterator(array_ + pos_index) < position) ++pos_index; // we need to do that because when we grow, we lose the iterator.

        while (size_ + n >= reserved_size_) grow();

        for (size_type i = size_ - 1; i + 1 > pos_index; --i) {
            array_[i + n] = array_[i];
        }

        for (size_type i = 0; i < n; ++i) {
            array_[pos_index + i] = val;
        }

        size_ += n;
    }

    template <class InputIterator>
    void insert (iterator position, InputIterator first, InputIterator last) {

        size_t n = 0;
        for (iterator it = first; it != last; ++it) {
            n++;
        }

        size_t pos_index = 0;
        while (iterator(array_ + pos_index) < position) ++pos_index; // we need to do that because when we grow, we lose the iterator.
       
        while (size_ + n >= reserved_size_) grow();

        for (size_type i = size_; i + 1 > pos_index; --i) {
            array_[i + n] = array_[i];
        }

        for (size_type i = 0; i < n; ++i) {
            array_[pos_index + i] = *first++;
        }
        size_ += n;
    }
    // --INSERT

    // ++ERASE
    iterator erase (iterator position) {
        for (iterator it = position;it + 1 != end();++it)
            *it = *(it + 1);
        size_ -= size_ ? 1 : 0;
        return position;
    }

    iterator erase (iterator first, iterator last) {
        size_t n = get_quantity(first, last);
        for (iterator it = first;it + n != end();++it)
            *it = *(it + n);
        size_ -= n > size_ ? size_ : n;
        return first;
    }
    // --ERASE

    // ONE_LINE
    bool empty()                      const { return size_ == 0; }
    void pop_back()                         { if (size_ > 0) --size_; }
    void clear()                            { size_ = 0; reserved_size_ = 0; }
    size_type max_size()              const { return std::numeric_limits<long>::max() / sizeof(T); }
    size_type capacity()              const { return reserved_size_; }
    size_type size()                  const { return size_; }
    iterator begin()                        { return iterator(array_); }
    const_iterator begin()            const { return const_iterator(array_); }
    iterator end()                          { return iterator(array_ + size_); }
    const_iterator end()              const { return const_iterator(array_ + size_); }
    reverse_iterator rbegin()               { return reverse_iterator(end()); }
    const_reverse_iterator rbegin()   const { return const_reverse_iterator(end()); }
    reverse_iterator rend()                 { return reverse_iterator(begin()); }
    const_reverse_iterator rend()     const { return const_reverse_iterator(begin()); }

    reference operator[] (size_type n)              { return array_[n]; }
    const_reference operator[] (size_type n) const  { return array_[n]; }
    reference at (size_type n)                      { return array_[n]; }
    const_reference at (size_type n) const          { return array_[n]; }
    reference front()                               { return array_[0]; }
    const_reference front() const                   { return array_[0]; }
    reference back()                                { return array_[size_ - 1]; }
    const_reference back() const                    { return array_[size_ - 1]; }

    class iterator {
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

    class const_iterator : public iterator {

    public:
        const_iterator(T *p=0) : iterator(p) {}
        const_iterator(const iterator& it) : iterator(it) {}
        ~const_iterator() {}

        const T &operator*()              const { return *this->current; }
        const T *operator->()             const { return this->current; }
        const T &operator[](int n)        const { return this->current[n]; }
    };

}; // ft::vector

}; // ft::


template <class T, class Alloc>
bool operator== (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
    if (lhs.size() != rhs.size())
        return false;
    typename ft::vector<T>::iterator lit = lhs.begin();
    typename ft::vector<T>::iterator rit = rhs.begin();
    while (lit != lhs.end()) {
        if (*lit++ != *rit++)
            return false;
    }
    return true;
}

template <class T, class Alloc>
bool operator!= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
    return !(lhs == rhs);
}

template <class T, class Alloc>
bool operator<  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
    if (lhs == rhs)
        return false;
    typename ft::vector<T>::iterator lit = lhs.begin();
    typename ft::vector<T>::iterator rit = rhs.begin();
    while (*lit == *rit && lit != lhs.end()) {
        ++lit;++rit;
    }
    if (*lit < *rit)
        return true;
    return false;
}

template <class T, class Alloc>
bool operator<= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
    return (lhs < rhs || lhs == rhs);
}

template <class T, class Alloc>
bool operator>  (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
    return !(lhs <= rhs);
}

template <class T, class Alloc>
bool operator>= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs) {
    return !(lhs < rhs);
}

template <class T, class Alloc>
void swap (ft::vector<T,Alloc>& x, ft::vector<T,Alloc>& y) {
    x.swap(y);
}

#endif
