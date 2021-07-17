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
# include <iostream>
# include <string>

# define DEBUG(x) std::cout << x << std::endl;


namespace ft {

template < class T >
class list {

public:

    // Member types
    typedef T                                       value_type;
    typedef T&                                      reference;
    typedef T*                                      pointer;
    typedef const T&                                const_reference;
    typedef const T*                                const_pointer;

    typedef std::ptrdiff_t                          difference_type;
    typedef size_t                                  size_type;

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

    ListNode *insertInternal(const T &e, ListNode *pos)
    {
        ListNode *n = new ListNode(e);

        size_++;
        n->next = pos;

        if(pos) {
            n->prev = pos->prev;
            pos->prev = n;
        }
        else {
            n->prev = tail_;
            tail_ = n;
        }
        if(n->prev) {
            n->prev->next = n;
        }
        else {
            head_ = n;
        }
        return n;
    }

    void removeInternal(ListNode *pos) {
        if(pos) {
            if(pos->prev)
                pos->prev->next = pos->next;

            if(pos->next)
                pos->next->prev = pos->prev;

            if(pos == head_)
                head_ = pos->next;

            if(pos == tail_)
                tail_ = pos->prev;

            delete pos;
            size_--;
        }
    }

// iterator
public:
    class iterator : public std::bidirectional_iterator_tag {

    public:
        iterator(ListNode *p=0) : pos_(p) {}

        T &operator*() {
            return pos_->data;
        }
        T *operator->() {
            return &(pos_->data);
        }
        bool operator!=(const iterator &rhs) {
            return this->pos_ != rhs.pos_;
        }
        iterator operator++(int) {
            pos_ = pos_->next;
            return *this;
        }
        iterator operator--(int) {
            pos_ = pos_->prev;
            return *this;
        }
        

    private:
        ListNode *pos_;

    };

    typedef std::reverse_iterator<iterator>              reverse_iterator;

// Actual list
private:
    ListNode    *head_;
    ListNode    *tail_;
    size_type   size_;

public:
    explicit list ()
    : head_(0), tail_(0), size_(0) {}


    explicit list (size_type n, const value_type& val = value_type())
    : size_(0) {
        insert(begin(), n, val);
    }

    template <class InputIterator>
    list (InputIterator first, InputIterator last, std::input_iterator_tag)
    : size_(0) {
        insert(begin(), first, last);
    }

    list (const list& x)
    : size_(0) {
        insert(begin(), x.begin(), x.end());
    }

    ~list()
    {
        ListNode *current( head_ );

        while(current)
        {
            ListNode *next( current->next );
            delete current;
            current = next;
        }
    }

    iterator insert (iterator position, const value_type& val) {

    }

    void insert (iterator position, size_type n, const value_type& val);

    template <class InputIterator>
    void insert (iterator position, InputIterator first, InputIterator last, std::input_iterator_tag);

    void push_back(const T &e) {
        insertInternal(e, 0);
    }

    void push_front(const T &e) {
        insertInternal(e, head_);
    }

    void pop_back() {
        removeInternal(tail_);
    }

    void pop_front() {
        removeInternal(head_);
    }

    T &front() {
        return head_->data;
    }

    T &back() {
        return tail_->data;
    }

    iterator begin() {
        return iterator(head_);
    }

    iterator end() {
        return iterator(0);
    }

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