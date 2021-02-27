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

#ifndef FT_LIST_HPP
# define FT_LIST_HPP
# include "alloc.hpp"
# include <limits>

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
    class const_iterator;
    typedef std::reverse_iterator<iterator>             reverse_iterator;
    typedef std::reverse_iterator<const_iterator>       const_reverse_iterator;

private:
    struct          ListNode;

    // Actual list
    allocator_type  alloc_;
    size_type       size_;
    ListNode        *head_;
    ListNode        *tail_;

    ListNode *after_tail() {
        static ListNode after_tail = ListNode(0);
        after_tail.next = head_;
        after_tail.prev = tail_;
        return &after_tail;
    };

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
        assign(first, last);
    }

    list (const list& x)
    : alloc_(x.alloc_), size_(0), head_(0), tail_(0) {
        assign(x.begin(), x.end());
    }

    list& operator= (const list& x)
    {
        if (this->head_ == x.head_)
            return *this;
        alloc_ = x.alloc_;
        assign(x.begin(), x.end());
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
            tail_ = n;
        }
        if (n->prev)
            n->prev->next = n;
        else
            head_ = n;

        return iterator(n);
    }

    void insert (iterator position, size_type n, const value_type& val) {
        while (n-- > 0)
            position = insert(position, val);
    }

    template <class InputIterator>
    void insert (iterator position, InputIterator first, InputIterator last) {
        while (first != last)
            insert(position, *first++);
    }
    // --INSERT

    // ++ERASE
    iterator erase (iterator position) {
        ListNode *n = (position++).current;

        if (n) {
            if (n->prev) n->prev->next = n->next;
            else head_ = n->next;
            if (n->next) n->next->prev = n->prev;
            else tail_ = n->prev;
            size_--;
            delete n;
        }
        return position;
    }

    iterator erase (iterator first, iterator last) {
        while (first != last)
            erase(first++);
        return last;
    }
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

    // ++RESIZE
    void resize (size_type n, value_type val = value_type()) {
        while (n < size_) pop_back();
        while (n > size_) push_back(val);
    }
    // --RESIZE

    // ++SPLICE
private:
    void unlink(list& x, iterator item) {
        ListNode *n = item.current;

        if (n) {
            if (n->prev) n->prev->next = n->next;
            else x.head_ = n->next;
            if (n->next) n->next->prev = n->prev;
            else x.tail_ = n->prev;
        }
    }

    void place(iterator position, iterator item) {
        ListNode *n = item.current;
        ListNode *p = position.current;

        if (!p) {
            n->prev = tail_;
            if (tail_ && head_) tail_->next = n;
            else head_ = n;
            n->next = 0;
            tail_ = n;
        }

        else {
            n->prev = p->prev;
            if (p->prev) p->prev->next = n;
            else head_ = n;
            n->next = p;
            p->prev = n;
        }
    }

public:
    void splice (iterator position, list& x) {
        splice(position, x, x.begin(), x.end());
    }

    void splice (iterator position, list& x, iterator i) {
        iterator j = i++;
        splice(position, x, j, i);
    }

    void splice (iterator position, list& x, iterator first, iterator last) {

        size_t count = 0;
        for (iterator it = first; it != last; ++it)
            count++;

        iterator it = first;
        for (size_t i=0;i<count;++i) {
            unlink(x, it);
            place(position, it++);
        }
    }
    // --SPLICE

    // ++REMOVE
    void remove (const value_type& val) {
        for (iterator it = begin(); it != end();) {
            if (*it == val)
                erase (it++);
            else
                it++;
        }
    }

    template <class Predicate>
    void remove_if (Predicate pred) {
        for (iterator it = begin(); it != end();) {
            if (pred(*it))
                erase(it++);
            else
                it++;
        }
    }
    // --REMOVE

    // ++SORT
    void sort() {
		list tmp_list;

		swap(tmp_list);
		clear();
		while(tmp_list.size_)
		{
			iterator smallest_it = tmp_list.begin();
			for (iterator it = tmp_list.begin(); it != tmp_list.end(); it++)
				if (*smallest_it > *it) smallest_it = it;
			push_back(*smallest_it);
			tmp_list.erase(smallest_it);
		}
	}

	template <class Compare>
	void sort (Compare comp) {
		list tmp_list;

		swap(tmp_list);
		clear();
		while(tmp_list.size_) {
			iterator smallest_it = tmp_list.begin();
			for (iterator it = tmp_list.begin(); it != tmp_list.end(); it++)
				if (!comp(*smallest_it, *it)) smallest_it = it;
			push_back(*smallest_it);
			tmp_list.erase(smallest_it);
		}
	}
    // --SORT

    // ++UNIQUE
	void unique() {
		ListNode *last_node = 0;

		for (iterator it = begin(); it != end();) {
			ListNode *cur_node = it.current;
			if (last_node && cur_node->data == last_node->data)
				erase(it++);
			else
				it++;
			last_node = cur_node;
		}
	}

	template <class BinaryPredicate>
	void unique (BinaryPredicate binary_pred) {
		ListNode *last_node = 0;

		for (iterator it = begin(); it != end();) {
			ListNode *cur_node = it.current;
			if (last_node && binary_pred(cur_node->data, last_node->data))
				erase(it++);
			else
				it++;
			last_node = cur_node;
		}
	}
    // --UNIQUE

    // ++MERGE
    void merge (list& x) {
		for (iterator it = begin(); it != end();) {
			if (*it > x.front())
				splice(it, x, x.begin());
			else
				it++;
		}
		splice(end(), x);
	}

	template <class Compare>
	void merge (list& x, Compare comp) {
		for (iterator it = begin(); it != end();) {
			if (x.head_ && comp(x.front(), *it))
				splice(it, x, x.begin());
			else
				it++;
		}
		splice(end(), x);
	}
    // --MERGE

    // ++REVERSE
	void reverse() {
		ListNode *new_head = tail_;
		ListNode *new_tail = head_;
		
		while (head_) {
			ListNode *new_next = head_->prev;

			head_->prev = head_->next;
			head_->next = new_next;
			head_ = head_->prev;
		}
		head_ = new_head;
		tail_ = new_tail;
	}
    // --REVERSE

    // ONE_LINE_STUFFS
    void clear()                            { while (size_) erase(begin()); }
    size_type size()                  const { return size_; }
    size_type max_size()              const { return std::numeric_limits<long>::max() / sizeof(ListNode); }
    bool empty()                      const { return size_ == 0; }
    void swap (list& x)                     { list tmp = *this;*this = x;x = tmp; }
    void pop_back()                         { erase(iterator(tail_)); }
    void pop_front()                        { erase(begin()); }
    void push_back(const T &e)              { insert(0, e); }
    void push_front(const T &e)             { insert(head_, e); }
    T &front()                              { return head_->data; }
    T &back()                               { return tail_->data; }
    iterator begin()                        { return iterator(head_); }
    const_iterator begin()            const { return const_iterator(head_); }
    iterator end()                          { return iterator(0); }
    const_iterator end()              const { return const_iterator(0); }
    reverse_iterator rbegin()               { return reverse_iterator(after_tail()); }
    const_reverse_iterator rbegin()   const { return const_reverse_iterator(after_tail()); }
    reverse_iterator rend()                 { return reverse_iterator(head_); }
    const_reverse_iterator rend()     const { return const_reverse_iterator(head_); }

// LIST_NODE
private:
    struct ListNode {
        T           data;
        ListNode    *next;
        ListNode    *prev;

        ListNode(const T &e) : data(e), next(0), prev(0) {}
    };

    ListNode *get_last(ListNode *n) {
        while (n && n->next) n = n->next;
        return n;
    }


// iterator
public:
    class iterator {
        friend class list<T>;
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

    protected:
        ListNode *current;
    };

    class const_iterator : public iterator {

    public:
        const_iterator(ListNode *p=0) : iterator(p) {}
        const_iterator(const iterator& it) : iterator(it) {}
        ~const_iterator() {}

        const T &operator*()              const { return this->current->data; }
        const T *operator->()             const { return &(this->current->data); }
    };

}; // list

}; // namespace ft::


template <class T, class Alloc>
bool operator== (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs) {
    if (lhs.size() != rhs.size())
        return false;
    typename ft::list<T>::iterator lit = lhs.begin();
    typename ft::list<T>::iterator rit = rhs.begin();
    while (lit != lhs.end()) {
        if (*lit++ != *rit++)
            return false;
    }
    return true;
}

template <class T, class Alloc>
bool operator!= (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs) {
    return !(lhs == rhs);
}

template <class T, class Alloc>
bool operator<  (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs) {
    if (lhs.size() > rhs.size() || lhs == rhs)
        return false;
    typename ft::list<T>::iterator lit = lhs.begin();
    typename ft::list<T>::iterator rit = rhs.begin();
    while (*lit == *rit) {
        ++lit;++rit;
    }
    if (*lit < *rit)
        return true;
    return false;
}

template <class T, class Alloc>
bool operator<= (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs) {
    return (lhs < rhs || lhs == rhs);
}

template <class T, class Alloc>
bool operator>  (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs) {
    return !(lhs <= rhs);
}

template <class T, class Alloc>
bool operator>= (const ft::list<T,Alloc>& lhs, const ft::list<T,Alloc>& rhs) {
    return !(lhs < rhs);
}

template <class T, class Alloc>
void swap (ft::list<T,Alloc>& x, ft::list<T,Alloc>& y) {
    x.swap(y);
}


#endif

// REFERENCES
// https://stackoverflow.com/questions/45847787/how-to-differentiate-fill-constructor-and-range-constructor-in-c11
// #if __APPLE__
// 	template <typename InputIterator, typename std::enable_if<std::__is_cpp17_input_iterator<InputIterator>::value>::type*>
// #else
// 	template <typename InputIterator, typename = std::_RequireInputIter<InputIterator> >
// #endif

// https://www.fluentcpp.com/2018/05/15/make-sfinae-pretty-1-what-value-sfinae-brings-to-code/
// https://h-deb.clg.qc.ca/Sujets/TrucsScouts/Comprendre_enable_if.html

// https://gcc.gnu.org/onlinedocs/gcc-4.6.2/libstdc++/api/a00588.html
// https://codereview.stackexchange.com/questions/201368/modern-c-singly-linked-list
// https://codereview.stackexchange.com/questions/185166/implementing-a-linked-list-in-c
// https://codefreakr.com/how-is-c-stl-list-implemented-internally/
