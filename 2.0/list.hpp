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

// REFERENCES
// https://gcc.gnu.org/onlinedocs/gcc-4.6.2/libstdc++/api/a00588.html
// https://codereview.stackexchange.com/questions/201368/modern-c-singly-linked-list
// https://codereview.stackexchange.com/questions/185166/implementing-a-linked-list-in-c
// https://codefreakr.com/how-is-c-stl-list-implemented-internally/

#ifndef FT_LIST_HPP
# define FT_LIST_HPP
# include "alloc.hpp"
# include <iostream>
# include <string>

# define DEBUG(x) std::cout << x << std::endl;

namespace ft {

template < class T, class Alloc = ft::allocator<T> >
class list {

public:

    // Member types
    typedef T                                           value_type;
    typedef Alloc                                       allocator_type;
    typedef typename allocator_type::reference	        reference;
    typedef typename allocator_type::pointer            pointer;
    typedef typename allocator_type::const_reference    const_reference;
    typedef typename allocator_type::const_pointer	    const_pointer;

    typedef std::ptrdiff_t                              difference_type;
    typedef size_t                                      size_type;

    // Only declarations
    class iterator;

private:
    struct          ListNode;

    // Actual list
    allocator_type  alloc_;
    size_type       size_;
    ListNode        *head_;
    ListNode        *tail_;

public:
    explicit list (const allocator_type& alloc = allocator_type())
    : alloc_(alloc), size_(0), head_(0), tail_(0) {}

    explicit list (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
    : alloc_(alloc), size_(0), head_(0), tail_(0) {
        insert(begin(), n, val);
    }

    template <class InputIterator>
    list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
    : alloc_(alloc), size_(0), head_(0), tail_(0) {
        insert(begin(), first, last);
    }

    list (const list& x)
    : alloc_(x.alloc_), size_(0), head_(0), tail_(0) {
        insert(begin(), x.begin(), x.end());
    }

    list& operator= (const list& x)
    {
        size_ = 0;
        insert(begin(), x.begin(), x.end());
        return *this;
    }

    ~list()
    {
        while (head_)
        {
            ListNode *next(head_->next);
            delete head_;
            head_ = next;
        }
    }

    size_type size() { return size_; }

    iterator insert (iterator position, const value_type& val) {
        ListNode *n = new ListNode(val);

        ++size_;
        n->prev = position.current;

        if (position.current) {
            n->next = position.current->next;
            position.current->next = n;
        }
        else {
            n->next = head_;
            head_ = n;
        }
        if (n->next)
            n->next->prev = n;
        else
            tail_ = n;

        return iterator(n); // ++?
    }

    void insert (iterator position, size_type n, const value_type& val) {
        while (n-- > 0)
            position = insert(position, val);
    }

    template <class InputIterator>
    void insert (iterator position, InputIterator first, InputIterator last) {
        while (first != last) {
            position = insert(position, *first);
            first++;
        }
    }

    void push_back(const T &e)      { insertInternal(e, 0); }
    void push_front(const T &e)     { insertInternal(e, head_); }
    void pop_back()                 { removeInternal(tail_); }
    void pop_front()                { removeInternal(head_); }
    T &front()                      { return head_->data; }
    T &back()                       { return tail_->data; }
    iterator begin()                { return iterator(head_); }
    const iterator begin()    const { return iterator(head_); }
    iterator end()                  { return iterator(0); }
    const iterator end()      const { return iterator(0); }

// INTERNAL
private:
    // LIST_NODE
    struct ListNode
    {
        T           data;
        ListNode    *next;
        ListNode    *prev;

        ListNode(const T &e) : data(e), next(0), prev(0) {}
    };


// iterator
public:
    class iterator : public std::bidirectional_iterator_tag {

    public:
        iterator(ListNode *p=0) : current(p) {}

        T &operator*()                          { return current->data; }
        T *operator->()                         { return &(current->data); }
        bool operator!=(const iterator &rhs)    { return this->current != rhs.current; }
        bool operator==(const iterator &rhs)    { return this->current == rhs.current; }
        iterator operator++(int)                { iterator tmp = iterator(current); current = current->next; return tmp; }
        iterator operator--(int)                { iterator tmp = iterator(current); current = current->prev; return tmp; }
        iterator &operator++()                  { current = current->next; return *this; }
        iterator &operator--()                  { current = current->prev; return *this; }

        ListNode *current;
    };

    typedef std::reverse_iterator<iterator>              reverse_iterator;

}; // list

}; // namespace ft::

#endif

// https://stackoverflow.com/questions/45847787/how-to-differentiate-fill-constructor-and-range-constructor-in-c11
// #if __APPLE__
// 	template <typename InputIterator, typename std::enable_if<std::__is_cpp17_input_iterator<InputIterator>::value>::type*>
// #else
// 	template <typename InputIterator, typename = std::_RequireInputIter<InputIterator> >
// #endif

// https://www.fluentcpp.com/2018/05/15/make-sfinae-pretty-1-what-value-sfinae-brings-to-code/

// https://h-deb.clg.qc.ca/Sujets/TrucsScouts/Comprendre_enable_if.html