/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 12:00:01 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/28 12:00:01 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_QUEUE_HPP
# define FT_QUEUE_HPP
# include "list.hpp"

namespace ft {

template <class T, class Container = ft::list<T> >
class queue {

public:
    typedef T                                           value_type;
    typedef Container                                   container_type;
    typedef size_t                                      size_type;

private:
    container_type c;

public:
    explicit queue (const container_type& ctnr = container_type()) : c(ctnr) {}

    bool empty() const                  { return c.empty(); }
    size_type size() const              { return c.size(); }
    value_type& front()                 { return c.front(); }
    const value_type& front() const     { return c.front(); }
    value_type& back()                  { return c.back(); }
    const value_type& back() const      { return c.back(); }
    void push (const value_type& val)   { c.push_back(val); }
    void pop()                          { c.erase(c.begin()); }

    friend bool operator== (const queue<T,Container>& lhs, const queue<T,Container>& rhs);
    friend bool operator!= (const queue<T,Container>& lhs, const queue<T,Container>& rhs);
    friend bool operator<  (const queue<T,Container>& lhs, const queue<T,Container>& rhs);
    friend bool operator<= (const queue<T,Container>& lhs, const queue<T,Container>& rhs);
    friend bool operator>  (const queue<T,Container>& lhs, const queue<T,Container>& rhs);
    friend bool operator>= (const queue<T,Container>& lhs, const queue<T,Container>& rhs);

}; // list

}; // namespace ft::

template <class T, class Container>
  bool operator== (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs)
  { return lhs.c == rhs.c; }

template <class T, class Container>
  bool operator!= (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs)
  { return lhs.c != rhs.c; }

template <class T, class Container>
  bool operator<  (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs)
  { return lhs.c < rhs.c; }

template <class T, class Container>
  bool operator<= (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs)
  { return lhs.c <= rhs.c; }

template <class T, class Container>
  bool operator>  (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs)
  { return lhs.c > rhs.c; }

template <class T, class Container>
  bool operator>= (const ft::queue<T,Container>& lhs, const ft::queue<T,Container>& rhs)
  { return lhs.c >= rhs.c; }

#endif
