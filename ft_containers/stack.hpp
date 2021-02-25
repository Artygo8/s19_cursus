/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 12:00:01 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/28 12:00:01 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_HPP
# define FT_STACK_HPP
# include "vector.hpp"

namespace ft {

template <class T, class Container = ft::vector<T> >
class stack {

public:
    typedef T                                           value_type;
    typedef Container                                   container_type;
    typedef size_t                                      size_type;

private:
    container_type c;

public:
    explicit stack (const container_type& ctnr = container_type()) : c(ctnr) {}
    
    bool empty()                      const { return c.empty(); }
    size_type size()                  const { return c.size(); }
    value_type& top()                       { return c.back(); }
    const value_type& top()           const { return c.back(); }
    void push (const value_type& val)       { c.push_back(val); }
    void pop()                              { c.pop_back(); }

    friend bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
    friend bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
    friend bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
    friend bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
    friend bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
    friend bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

}; // list

}; // namespace ft::

template <class T, class Container>
  bool operator== (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
  { return lhs.c == rhs.c; }

template <class T, class Container>
  bool operator!= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
  { return lhs.c != rhs.c; }

template <class T, class Container>
  bool operator<  (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
  { return lhs.c < rhs.c; }

template <class T, class Container>
  bool operator<= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
  { return lhs.c <= rhs.c; }

template <class T, class Container>
  bool operator>  (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
  { return lhs.c > rhs.c; }

template <class T, class Container>
  bool operator>= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
  { return lhs.c >= rhs.c; }

#endif
