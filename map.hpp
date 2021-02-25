/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 12:00:01 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/28 12:00:01 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_HPP
# define FT_MAP_HPP
# include "alloc.hpp"
# include <iostream>
# include <string>

namespace ft {

template < class Key,                                     // map::key_type
           class T,                                       // map::mapped_type
           class Compare = std::less<Key>,                     // map::key_compare
           class Alloc = allocator<std::pair<const Key,T> >    // map::allocator_type
           > class map {

public:

    // Member types
    typedef Key                                         key_type;
    typedef T                                           mapped_type;
    typedef std::pair<const Key,T>                      value_type;
    typedef Compare                                     key_compare;
    // value compare ?
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

    struct MapNode {
        key_type key;
        mapped_type value;
        MapNode *parent;
        MapNode *smaller;
        MapNode *bigger;

        MapNode(key_type key, mapped_type value)
        : key(key), value(value), parent(0), smaller(0), bigger(0) {}
    };

    MapNode *root_;
    key_compare comp_;
    allocator_type alloc_;

public:

    // +++ ft::map::map +++
    explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
    : root_(0), comp_(comp), alloc_(alloc) {} 

    template <class InputIterator>
    map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
    : root_(0), comp_(comp), alloc_(alloc) {
        (void) first;
        (void) last;
    } 

    map (const map& x);
    : root_(x.root), comp_(x.comp), alloc_(x.alloc) {}
    // --- ft::map::map ---

    // +++ ft::map::~map +++
    ~map() {}
    // --- ft::map::~map ---



    // +++ ft::map::operator[] +++
    mapped_type& operator[] (const key_type& k) {
        // return (*((insert(make_pair(k,mapped_type()))).first)).second;
    }
    // --- ft::map::operator[] ---


    iterator begin() {

    }
    const_iterator begin() const {
        
    }


private:
    class iterator {
    public:

        typedef iterator                            iterator_type;
        typedef std::bidirectional_iterator_tag     iterator_category;
        typedef Key                                 key_type;
        typedef T                                   mapped_type;
        typedef std::pair<const Key,T>              value_type;
        typedef value_type&                         reference;
        typedef value_type*                         pointer;

        typedef std::ptrdiff_t                      difference_type;
        typedef size_t                              size_type;

        iterator(MapNode* p = 0) : current(p) {}
        iterator(const iterator& it) : current(it.current) {}
        ~iterator() {}

        iterator operator= (const iterator& it) { this->current = it.current; return *this; }

        bool operator!=(const iterator &rhs)    { return current != rhs.current; }
        bool operator==(const iterator &rhs)    { return current == rhs.current; }
        T &operator*()                          { return *current; }
        T *operator->()                         { return current; }
        iterator operator++(int)                { iterator tmp = iterator(current++); return tmp; }
        iterator operator--(int)                { iterator tmp = iterator(current--); return tmp; }

        iterator &operator++() {
            if (current && current->bigger) current = current->bigger;
            else if (current && current->parent && current->parent->smaller = current) current = current->parent;
            else current = 0;
            return *this;
        }
        
        iterator &operator--() {
            if (current && current->bigger) current = current->bigger;
            else if (current && current->parent && current->parent->smaller = current) current = current->parent;
            else current = 0;
            return *this;
        }

    protected:
        MapNode* current;
    };

}; // ft::vector

}; // ft::

#endif