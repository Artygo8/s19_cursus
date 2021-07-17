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
    typedef std::reverse_iterator<iterator>             reverse_iterator;

private:
    struct          ListNode;

    // Actual list
    allocator_type  alloc_;
    size_type       size_;
    ListNode        *head_;
    ListNode        *tail_;
    ListNode        *after_tail;

    void set_after_tail() { after_tail->next = head_; after_tail->prev = tail_; }
    void set_head(ListNode *n) { head_ = n; set_after_tail(); };
    void set_tail(ListNode *n) { tail_ = n; set_after_tail(); };

public:
    explicit list (const allocator_type& alloc = allocator_type())
    : alloc_(alloc), size_(0), head_(0), tail_(0) {
        after_tail = new ListNode(0);
    }

    explicit list (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
    : alloc_(alloc), size_(0), head_(0), tail_(0) {
        after_tail = new ListNode(0);
        insert(begin(), n, val);
    }

    template <class InputIterator>
    list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
    : alloc_(alloc), size_(0), head_(0), tail_(0) {
        after_tail = new ListNode(0);
        insert(begin(), first, last);
    }

    list (const list& x)
    : alloc_(x.alloc_), size_(0), head_(0), tail_(0) {
        after_tail = new ListNode(0);
        insert(begin(), x.begin(), x.end());
    }

    list& operator= (const list& x)
    {
        // if (*this == x)
        //     return *this;
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
        delete after_tail;
    }

    size_type   size() { return size_; }
    size_type   max_size() { return std::numeric_limits<long>::max() / sizeof(ListNode);}
    bool        empty() { return size_ == 0; }

	void swap (list& x)
	{
		list tmp = *this;
		*this = x;
		x = tmp;
	}

    // ++INSERT
    iterator insert (iterator position, const value_type& val) {
        ListNode *n = new ListNode(val);

        ++size_;
        n->next = position.current;

        if (position.current) {
            n->prev = position.current->prev;
            position.current->prev = n;
        }
        else {
            n->prev = tail_;
            set_tail(n);
        }
        if (n->prev)
            n->prev->next = n;
        else
            set_head(n);

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
    // --INSERT
    // ++ERASE
    iterator erase (iterator position) {
        ListNode *n = (position++).current;

        if (n) {
            if (n->prev) n->prev->next = n->next;
            else set_head(n->next);
            if (n->next) n->next->prev = n->prev;
            else set_tail(n->prev);
            size_--;
            delete n;
        }
        return position;
    }

    iterator erase (iterator first, iterator last) {
        while (first != last) {
            erase(first++);
        }
        return last;
    }

    void    clear() { while (size_) erase(begin()); }
    // --ERASE

    // ++ASSIGN
    template <class InputIterator>
    void assign (InputIterator first, InputIterator last) {
        clear();
        insert(begin(), first, last);
    }

    void assign (size_type n, const value_type& val) {
        clear();
        while (n--) push_back(val);
    }
    // --ASSIGN

    void pop_back()                 { erase(iterator(tail_)); }
    void pop_front()                { erase(begin()); }

    void push_back(const T &e)      { insert(0, e); }
    void push_front(const T &e)     { insert(head_, e); }
    T &front()                      { return head_->data; }
    T &back()                       { return tail_->data; }
    iterator begin()                { return iterator(head_); }
    const iterator begin()    const { return iterator(head_); }
    iterator end()                  { return iterator(0); }
    const iterator end()      const { return iterator(0); }
    reverse_iterator rbegin()               { return reverse_iterator(after_tail); }
    const reverse_iterator rbegin()   const { return reverse_iterator(after_tail); }
    reverse_iterator rend()                 { return reverse_iterator(head_); }
    const reverse_iterator rend()     const { return reverse_iterator(head_); }


// LIST_NODE
private:
    struct ListNode
    {
        T           data;
        ListNode    *next;
        ListNode    *prev;

        ListNode(const T &e) : data(e), next(0), prev(0) {}
    };


// iterator
public:
    class iterator {

    public:
        // typedef iterator                            iterator_type;
        typedef std::bidirectional_iterator_tag     iterator_category;
        typedef T                                   value_type;
        typedef T&                                  reference;
        typedef T*                                  pointer;

        typedef std::ptrdiff_t                      difference_type;
        typedef size_t                              size_type;


        iterator(ListNode* p=0) : current(p) {}
        iterator(const iterator& it) : current(it.current) {}
        ~iterator() {}

        iterator operator= (const iterator& it) { this->current = it.current; return *this; }

        T &operator*()                          { return current->data; }
        T *operator->()                         { return &(current->data); }
        bool operator!=(const iterator &rhs)    { return this->current != rhs.current; }
        bool operator==(const iterator &rhs)    { return this->current == rhs.current; }
        iterator operator++(int)                { iterator tmp = iterator(current); ++*this; return tmp; }
        iterator operator--(int)                { iterator tmp = iterator(current); --*this; return tmp; }
        iterator &operator++()                  { current = current->next; return *this; }
        iterator &operator--()                  { current = current->prev; return *this; }

        ListNode *current;
    };


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