/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 12:00:01 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/28 12:00:01 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_HPP
# define FT_STACK_HPP
# include "Vector.hpp"

namespace ft {

template <class T, class C = ft::Vector<T> >
class Stack {

public:
    typedef T                                           value_type;
    typedef C                                   container_type;
    typedef size_t                                      size_type;

private:
    container_type c;

public:
    explicit Stack (const container_type& ctnr = container_type()) : c(ctnr) {}

    bool empty()                      const { return c.empty(); }
    size_type size()                  const { return c.size(); }
    value_type& top()                       { return c.back(); }
    const value_type& top()           const { return c.back(); }
    void push (const value_type& val)       { c.push_back(val); }
    void pop()                              { c.pop_back(); }

template <class T1, class C1>
    friend bool operator== (const Stack<T1,C1>&, const Stack<T1,C1>&);
template <class T1, class C1>
    friend bool operator<  (const Stack<T1,C1>&, const Stack<T1,C1>&);

}; // Stack

template <class T, class C>
  bool operator== (const Stack<T, C>& lhs, const Stack<T, C>& rhs)
  { return lhs.c == rhs.c; }

template <class T, class C>
  bool operator!= (const Stack<T, C>& lhs, const Stack<T, C>& rhs)
  { return !(lhs == rhs); }

template <class T, class C>
  bool operator<  (const Stack<T, C>& lhs, const Stack<T, C>& rhs)
  { return lhs.c < rhs.c; }

template <class T, class C>
  bool operator<= (const Stack<T, C>& lhs, const Stack<T, C>& rhs)
  { return lhs < rhs || lhs == rhs; }

template <class T, class C>
  bool operator>  (const Stack<T, C>& lhs, const Stack<T, C>& rhs)
  { return !(lhs < rhs || lhs == rhs); }

template <class T, class C>
  bool operator>= (const Stack<T, C>& lhs, const Stack<T, C>& rhs)
  { return !(lhs < rhs); }


}; // namespace ft

#endif
