/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
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

// PAIR
template <class T1, class T2>
struct pair {
    typedef T1              first_type;
    typedef T2              second_type;

    first_type first;
    second_type second;

    pair() : first(0), second(0) {}
    pair (const pair& pr) : first(pr.first), second(pr.second) {}
    pair (const first_type& a, const second_type& b) : first(a), second(b) {}

    pair& operator= (const pair& pr) {
        this->first = pr.first;
        this->second = pr.second;
        return *this;
    }
};

template <class T1, class T2>
  bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return lhs.first==rhs.first && lhs.second==rhs.second; }

template <class T1, class T2>
  bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return !(lhs==rhs); }

template <class T1, class T2>
  bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

template <class T1, class T2>
  bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return !(rhs<lhs); }

template <class T1, class T2>
  bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return rhs<lhs; }

template <class T1, class T2>
  bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return !(lhs<rhs); }

// MAKE_PAIR
template <class T1, class T2>
pair<T1, T2> make_pair(const T1& x, const T2& y) {
    return pair<T1, T2>(x, y);
}

// MAP
template < class Key,                                     // Map::key_type
           class T,                                       // Map::Mapped_type
           class Compare = std::less<Key>,                     // Map::key_compare
           class Alloc = allocator<ft::pair<const Key,T> >    // Map::allocator_type
           > class Map {

public:

    // Member types
    typedef Key                                         key_type;
    typedef T                                           Mapped_type;
    typedef ft::pair<const Key,T>                       value_type;
    typedef Compare                                     key_compare;

    class value_compare {   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
        friend class Map;
    protected:
        Compare comp;
        value_compare (Compare c) : comp(c) {}  // constructed with Map's comparison object
    public:
        typedef bool result_type;
        typedef value_type first_argument_type;
        typedef value_type second_argument_type;
        bool operator() (const value_type& x, const value_type& y) const {
            return comp(x.first, y.first);
        }
    };

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

protected:

    struct MapNode {
        value_type  data;
        MapNode     *parent;
        MapNode     *prev;
        MapNode     *next;

        MapNode(value_type data)
        : data(data), parent(0), prev(0), next(0) {}
    };

    MapNode *root_of_root() {
        static MapNode ror(make_pair<const Key, T>(0,0));
        ror.parent = 0;
        ror.prev = root_;
        ror.next = root_;
        return &ror;
    }

    MapNode         *root_;
    size_type       size_;
    key_compare     comp_;
    allocator_type  alloc_;

public:

    explicit Map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
    : root_(0), size_(0), comp_(comp), alloc_(alloc) {}

    template <class InputIterator>
    Map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
    : root_(0), size_(0), comp_(comp), alloc_(alloc) {
        insert(first, last);
    }

    Map (const Map& x)
    : root_(0), size_(0), comp_(x.comp_), alloc_(x.alloc_) {
        insert(x.begin(), x.end());
    }

private:
    void delete_sons(MapNode* n) {
        if (n) {
            if (n->prev) delete_sons(n->prev);
            if (n->next) delete_sons(n->next);
            delete n;
        }
    }

public:
    ~Map() {
        clear();
    }

    Map& operator= (const Map& x) {
        if (this->root_ == x.root_)
            return *this;
        clear();
        insert(x.begin(), x.end());
        return *this;
    }

    // +++ ft::Map::operator[] +++
    Mapped_type& operator[] (const key_type& k) {
        return (*(((insert(ft::make_pair<const Key,T>(k, Mapped_type())))).first)).second;
    }
    // --- ft::Map::operator[] ---

    // ++ INSERT
    pair<iterator,bool> insert (const value_type& val) {
        if (!root_) {
            root_ = new MapNode(val);
            ++size_;
            return make_pair(begin(),true);
        }
        MapNode *tmp = root_;
        while (true) {
            if (tmp->data.first == val.first) {
                return make_pair(iterator(tmp), false);
            } 
            if (!comp_(val.first,tmp->data.first)) {
                if (tmp->next == 0) {
                    tmp->next = new MapNode(val);
                    tmp->next->parent = tmp;
                    ++size_;
                    return make_pair(iterator(tmp->next), true);
                }
                else
                    tmp = tmp->next;
            }
            else {
                if (tmp->prev == 0) {
                    tmp->prev = new MapNode(val);
                    tmp->prev->parent = tmp;
                    ++size_;
                    return make_pair(iterator(tmp->prev), true);
                }
                else
                    tmp = tmp->prev;
            }
        }
    }

    iterator insert (iterator position, const value_type& val) { // remonter jusqu'a un compare different, puis redescendre et chercher.
        iterator it = position;
        // go forward
        while (comp_((*it).first,val.first)) {
            iterator tmpit = it;
            if (++it == end()) {
                MapNode *last = tmpit.current;
                MapNode *n = new MapNode(val);
                n->parent = last;
                last->next = n;
                return ++tmpit;
            }
        }
        if ((*it).first == val.first) {
            (*it).second = val.second;
            return it;
        }
        // go backward
        while (!comp_((*it).first,val.first)) {
            iterator tmpit = it;
            if (--it == end()) {
                MapNode *first = tmpit.current;
                MapNode *n = new MapNode(val);
                n->parent = first;
                first->next = n;
                return --tmpit;
            }
        }
        if ((*it).first == val.first) {
            (*it).second = val.second;
            return it;
        }
        MapNode *inser = it.current;
        if (!inser->next) {
            MapNode *n = new MapNode(val);
            n->parent = inser;
            inser->next = n;
            return it;
        }
        else {
            inser = (++it).current;
            MapNode *n = new MapNode(val);
            n->parent = inser;
            inser->prev = n;
            return it;
        }
    }

    template <class InputIterator>
    void insert (InputIterator first, InputIterator last) {
        for (iterator it = first; it != last; ++it)
            insert(*it);
    }
    // -- INSERT

    // ++ ERSASE
    void erase (iterator position) {
        MapNode *tmp = position.current;
        if (!tmp) return ;
        iterator it = position;
        // its a leaf
        if (!tmp->next && !tmp->prev) {
            if (tmp->parent && tmp->parent->next == tmp)
                tmp->parent->next = 0;
            if (tmp->parent && tmp->parent->prev == tmp)
                tmp->parent->prev = 0;
            delete tmp;
            --size_;
        }
        // its a branch, replace it
        else {
            if (tmp->next) {
                ++it;
                it.current->prev = tmp->prev;
                if (tmp->prev) tmp->prev->parent = it.current;
            }
            else { // because it is not a leaf
                --it;
                it.current->next = tmp->next;
                if (tmp->next) tmp->next->parent = it.current;
            }
            // detach tmp
            if (tmp->parent && tmp->parent->next == tmp)
                tmp->parent->next = it.current;
            else if (tmp->parent && tmp->parent->prev == tmp)
                tmp->parent->prev = it.current;
            else {
                root_ = it.current;
            }
            // detach it
            if (it.current->parent && it.current->parent->next == it.current)
                it.current->parent->next = 0;
            else if (it.current->parent && it.current->parent->prev == it.current)
                it.current->parent->prev = 0;
            it.current->parent = tmp->parent;
            delete tmp;
            --size_;
        }
        if (size_ == 0) root_ = 0;
    }
    
    size_type erase (const key_type& k) {
        if (find(k) == end())
            return 0;
        erase(find(k));
        return 1;
    }

    void erase (iterator first, iterator last) {
        for (iterator it = first; it != last;)
            erase(it++);
    }
    // -- ERASE

    // ++ FIND
    iterator find (const key_type& k) {
        MapNode *tmp = root_;
        while (true) {
            if (tmp->data.first == k) {
                return iterator(tmp);
            } 
            if (!comp_(k,tmp->data.first)) {
                if (tmp->next == 0)
                    return end();
                else
                    tmp = tmp->next;
            }
            else {
                if (tmp->prev == 0)
                    return end();
                else
                    tmp = tmp->prev;
            }
        }
    }

    const_iterator find (const key_type& k) const {
        MapNode *tmp = root_;
        while (true) {
            if (tmp->data.first == k) {
                return iterator(tmp);
            } 
            if (!comp_(k,tmp->data.first)) {
                if (tmp->next == 0)
                    return end();
                else
                    tmp = tmp->next;
            }
            else {
                if (tmp->prev == 0)
                    return end();
                else
                    tmp = tmp->prev;
            }
        }
    }
    // -- FIND
private:
    template<class U>
    void my_swap(U &lhs, U&rhs) {
        U tmp = lhs;
        lhs = rhs;
        rhs = tmp;
    }

public:
    void swap (Map& x) {
        my_swap(root_, x.root_);
        my_swap(size_, x.size_);
        my_swap(comp_, x.comp_);
        my_swap(alloc_, x.alloc_);
    }

    bool empty() const { return size_ == 0; }
    size_type size() const { return size_; }
    size_type max_size() const { return std::numeric_limits<long>::max() / sizeof(MapNode); }

    void clear() { delete_sons(root_); root_ = 0; size_ = 0; }

    key_compare key_comp() const { return comp_; }
    value_compare value_comp() const { return value_compare(comp_); }

    size_type count (const key_type& k) const {
        if (find(k) != end()) return 1;
        else return 0;
    }

    iterator lower_bound (const key_type& k) {
        for (iterator it = begin();it != end();++it) {
            if (!comp_((*it).first,k))
                return it;
        }
        return end();
    }

    const_iterator lower_bound (const key_type& k) const {
        for (iterator it = begin();it != end();++it) {
            if (!comp_((*it).first,k))
                return it;
        }
        return end();
    }

    iterator upper_bound (const key_type& k) {
        for (iterator it = begin();it != end();++it) {
            if (comp_(k,(*it).first))
                return it;
        }
        return end();
    }

    const_iterator upper_bound (const key_type& k) const {
        for (iterator it = begin();it != end();++it) {
            if (comp_(k,(*it).first))
                return it;
        }
        return end();
    }

    pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
        for (iterator it = begin();it != end();++it) {
            if (k == (*it).first) {
                iterator next_it = it;
                return make_pair(it, ++next_it);
            }
            if (comp_(k,(*it).first)) {
                return make_pair(it,it);
            }
        }
        return make_pair(end(), end());
    }

    pair<iterator,iterator>             equal_range (const key_type& k) {
        for (iterator it = begin();it != end();++it) {
            if (k == (*it).first) {
                iterator next_it = it;
                return make_pair(it, ++next_it);
            }
            if (comp_(k,(*it).first)) {
                return make_pair(it,it);
            }
        }
        return make_pair(end(), end());
    }

    iterator begin() {
        MapNode *tmp = root_;
        while (tmp && tmp->prev) {
            tmp = tmp->prev;
        }
        return iterator(tmp);
    }

    const_iterator begin() const {
        MapNode *tmp = root_;
        while (tmp && tmp->prev) {
            tmp = tmp->prev;
        }
        return iterator(tmp);
    }

    iterator end() { return iterator(0); }
    const_iterator end() const { return iterator(0); }
    reverse_iterator rbegin() { return reverse_iterator(root_of_root()); }
    const_reverse_iterator rbegin() const { return reverse_iterator(root_of_root()); }
    reverse_iterator rend() { return reverse_iterator(begin()); }
    const_reverse_iterator rend() const { return reverse_iterator(begin()); }

// iterator
    class iterator {
    public:
        friend class Map;
        typedef iterator                            iterator_type;
        typedef std::bidirectional_iterator_tag     iterator_category;
        typedef Key                                 key_type;
        typedef T                                   Mapped_type;
        typedef ft::pair<const Key,T>               value_type;
        typedef value_type&                         reference;
        typedef value_type*                         pointer;

        typedef std::ptrdiff_t                      difference_type;
        typedef size_t                              size_type;

        iterator(MapNode* p = 0) : current(p) {}
        iterator(const iterator& it) : current(it.current) {}
        ~iterator() {}

        iterator operator= (const iterator& it) { current = it.current; return *this; }

        bool operator!=(const iterator &rhs)  const { return current != rhs.current; }
        bool operator==(const iterator &rhs)  const { return current == rhs.current; }
        value_type &operator*()                     { return current->data; }
        value_type *operator->()                    { return &(current->data); }
        iterator operator++(int)                    { iterator tmp = *this; ++*this; return tmp; }
        iterator operator--(int)                    { iterator tmp = *this; --*this; return tmp; }

    private:
        void goto_left_child() {
            while (current->prev) {
                current = current->prev;
            }
        }

        void goto_right_child() {
            while (current->next) {
                current = current->next;
            }
        }

    public:
        // get the first root that has a next different than what we have
        iterator &operator++() {
            if (current->next) {
                current = current->next;
                goto_left_child();
                return *this;
            }
            while (current->parent) {
                if (current->parent->next != current) {
                    current = current->parent;
                    return *this;
                }
                current = current->parent;
            }
            current = 0;
            return *this;
        }
        
        iterator &operator--() {
            if (current->prev) {
                current = current->prev;
                goto_right_child();
                return *this;
            }
            while (current->parent) {
                if (current->parent->prev != current) {
                    current = current->parent;
                    return *this;
                }
                current = current->parent;
            }
            current = 0;
            return *this;
        }

    protected:
        MapNode* current;
    };

    class const_iterator : public iterator {

    public:
        const_iterator(MapNode *p=0) : iterator(p) {}
        const_iterator(const iterator& it) : iterator(it) {}
        ~const_iterator() {}

        const T &operator*()              const { return this->current->data; }
        const T *operator->()             const { return &(this->current->data); }
    };

}; // ft::vector

}; // ft::

#endif