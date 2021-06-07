/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 12:00:01 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/28 12:00:01 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_QUEUE_HPP
# define FT_QUEUE_HPP
# include "List.hpp"

namespace ft {

template <class T, class Container = ft::List<T> >
class Queue {

public:
    typedef T                                           value_type;
    typedef Container                                   container_type;
    typedef size_t                                      size_type;

private:
    container_type c;

public:
    explicit Queue (const container_type& ctnr = container_type()) : c(ctnr) {}

    bool empty() const                  { return c.empty(); }
    size_type size() const              { return c.size(); }
    value_type& front()                 { return c.front(); }
    const value_type& front() const     { return c.front(); }
    value_type& back()                  { return c.back(); }
    const value_type& back() const      { return c.back(); }
    void push (const value_type& val)   { c.push_back(val); }
    void pop()                          { c.erase(c.begin()); }

template <class T1, class C1>
    friend bool operator== (const Queue<T1,C1>& lhs, const Queue<T1,C1>& rhs);
template <class T1, class C1>
    friend bool operator<  (const Queue<T1,C1>& lhs, const Queue<T1,C1>& rhs);

}; // Queue

template <class T, class C>
  bool operator== (const Queue<T, C>& lhs, const Queue<T, C>& rhs)
  { return lhs.c == rhs.c; }

template <class T, class C>
  bool operator!= (const Queue<T, C>& lhs, const Queue<T, C>& rhs)
  { return !(lhs == rhs); }

template <class T, class C>
  bool operator<  (const Queue<T, C>& lhs, const Queue<T, C>& rhs)
  { return lhs.c < rhs.c; }

template <class T, class C>
  bool operator<= (const Queue<T, C>& lhs, const Queue<T, C>& rhs)
  { return lhs < rhs || lhs == rhs; }

template <class T, class C>
  bool operator>  (const Queue<T, C>& lhs, const Queue<T, C>& rhs)
  { return !(lhs < rhs || lhs == rhs); }

template <class T, class C>
  bool operator>= (const Queue<T, C>& lhs, const Queue<T, C>& rhs)
  { return !(lhs < rhs); }

}; // namespace ft::

#endif
