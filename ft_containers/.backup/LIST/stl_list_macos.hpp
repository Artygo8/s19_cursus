// -*- C++ -*-
//===---------------------------- list ------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef _LIBCPP_LIST
#define _LIBCPP_LIST

/*
    list synopsis

namespace std
{

template <class T, class Alloc = allocator<T> >
class list
{
public:

    // types:
    typedef T value_type;
    typedef Alloc allocator_type;
    typedef typename allocator_type::reference reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::pointer pointer;
    typedef typename allocator_type::const_pointer const_pointer;
    typedef implementation-defined iterator;
    typedef implementation-defined const_iterator;
    typedef implementation-defined size_type;
    typedef implementation-defined difference_type;
    typedef reverse_iterator<iterator> reverse_iterator;
    typedef reverse_iterator<const_iterator> const_reverse_iterator;

    list()
        noexcept(is_nothrow_default_constructible<allocator_type>::value);
    explicit list(const allocator_type& a);
    explicit list(size_type n);
    explicit list(size_type n, const allocator_type& a); // C++14
    list(size_type n, const value_type& value);
    list(size_type n, const value_type& value, const allocator_type& a);
    template <class Iter>
        list(Iter first, Iter last);
    template <class Iter>
        list(Iter first, Iter last, const allocator_type& a);
    list(const list& x);
    list(const list&, const allocator_type& a);
    list(list&& x)
        noexcept(is_nothrow_move_constructible<allocator_type>::value);
    list(list&&, const allocator_type& a);
    list(initializer_list<value_type>);
    list(initializer_list<value_type>, const allocator_type& a);

    ~list();

    list& operator=(const list& x);
    list& operator=(list&& x)
        noexcept(
             allocator_type::propagate_on_container_move_assignment::value &&
             is_nothrow_move_assignable<allocator_type>::value);
    list& operator=(initializer_list<value_type>);
    template <class Iter>
        void assign(Iter first, Iter last);
    void assign(size_type n, const value_type& t);
    void assign(initializer_list<value_type>);

    allocator_type get_allocator() const noexcept;

    iterator begin() noexcept;
    const_iterator begin() const noexcept;
    iterator end() noexcept;
    const_iterator end() const noexcept;
    reverse_iterator rbegin() noexcept;
    const_reverse_iterator rbegin() const noexcept;
    reverse_iterator rend() noexcept;
    const_reverse_iterator rend() const noexcept;
    const_iterator cbegin() const noexcept;
    const_iterator cend() const noexcept;
    const_reverse_iterator crbegin() const noexcept;
    const_reverse_iterator crend() const noexcept;

    reference front();
    const_reference front() const;
    reference back();
    const_reference back() const;

    bool empty() const noexcept;
    size_type size() const noexcept;
    size_type max_size() const noexcept;

    template <class... Args>
        reference emplace_front(Args&&... args); // reference in C++17
    void pop_front();
    template <class... Args>
        reference emplace_back(Args&&... args);  // reference in C++17
    void pop_back();
    void push_front(const value_type& x);
    void push_front(value_type&& x);
    void push_back(const value_type& x);
    void push_back(value_type&& x);
    template <class... Args>
        iterator emplace(const_iterator position, Args&&... args);
    iterator insert(const_iterator position, const value_type& x);
    iterator insert(const_iterator position, value_type&& x);
    iterator insert(const_iterator position, size_type n, const value_type& x);
    template <class Iter>
        iterator insert(const_iterator position, Iter first, Iter last);
    iterator insert(const_iterator position, initializer_list<value_type> il);

    iterator erase(const_iterator position);
    iterator erase(const_iterator position, const_iterator last);

    void resize(size_type sz);
    void resize(size_type sz, const value_type& c);

    void swap(list&)
        noexcept(allocator_traits<allocator_type>::is_always_equal::value);  // C++17
    void clear() noexcept;

    void splice(const_iterator position, list& x);
    void splice(const_iterator position, list&& x);
    void splice(const_iterator position, list& x, const_iterator i);
    void splice(const_iterator position, list&& x, const_iterator i);
    void splice(const_iterator position, list& x, const_iterator first,
                                                  const_iterator last);
    void splice(const_iterator position, list&& x, const_iterator first,
                                                  const_iterator last);

    size_type remove(const value_type& value);       // void before C++20
    template <class Pred>
      size_type remove_if(Pred pred);                // void before C++20
    size_type unique();                              // void before C++20
    template <class BinaryPredicate>
      size_type unique(BinaryPredicate binary_pred); // void before C++20
    void merge(list& x);
    void merge(list&& x);
    template <class Compare>
        void merge(list& x, Compare comp);
    template <class Compare>
        void merge(list&& x, Compare comp);
    void sort();
    template <class Compare>
        void sort(Compare comp);
    void reverse() noexcept;
};


template <class InputIterator, class Allocator = allocator<typename iterator_traits<InputIterator>::value_type>>
    list(InputIterator, InputIterator, Allocator = Allocator())
    -> list<typename iterator_traits<InputIterator>::value_type, Allocator>;  // C++17

template <class T, class Alloc>
    bool operator==(const list<T,Alloc>& x, const list<T,Alloc>& y);
template <class T, class Alloc>
    bool operator< (const list<T,Alloc>& x, const list<T,Alloc>& y);
template <class T, class Alloc>
    bool operator!=(const list<T,Alloc>& x, const list<T,Alloc>& y);
template <class T, class Alloc>
    bool operator> (const list<T,Alloc>& x, const list<T,Alloc>& y);
template <class T, class Alloc>
    bool operator>=(const list<T,Alloc>& x, const list<T,Alloc>& y);
template <class T, class Alloc>
    bool operator<=(const list<T,Alloc>& x, const list<T,Alloc>& y);

template <class T, class Alloc>
    void swap(list<T,Alloc>& x, list<T,Alloc>& y)
         noexcept(noexcept(x.swap(y)));

template <class T, class Allocator, class U>
    void erase(list<T, Allocator>& c, const U& value);       // C++20
template <class T, class Allocator, class Predicate>
    void erase_if(list<T, Allocator>& c, Predicate pred);    // C++20

}  // std

*/

#include <__config>

#include <memory>
#include <limits>
#include <initializer_list>
#include <iterator>
#include <algorithm>
#include <type_traits>
#include <__cxx_version>

#include <__debug>

_LIBCPP_PUSH_MACROS
#include <__undef_macros>


_LIBCPP_BEGIN_NAMESPACE_STD


template <class _Tp, class _VoidPtr> struct __list_node;
template <class _Tp, class _VoidPtr> struct __list_node_base;

// |    o     |                      |                   o     |                  |              o|
// |    .,---.|---     ,---.,---.,---|,---.    ,---.,---..,---.|--- ,---.,---.    |--- ,---.,---..|---
// |    |`---.|        |   ||   ||   ||---'    |   ||   |||   ||    |---'|        |    |    ,---|||
// `---'``---'`---'    `   '`---'`---'`---'    |---'`---'``   '`---'`---'`        `---'`    `---^``---'

template <class _Tp, class _VoidPtr>
struct __list_node_pointer_traits {

  typedef typename __rebind_pointer<_VoidPtr, __list_node<_Tp, _VoidPtr> >::type                                    __node_pointer;
  typedef typename __rebind_pointer<_VoidPtr, __list_node_base<_Tp, _VoidPtr> >::type                               __base_pointer;
  typedef __base_pointer                                                                                            __link_pointer;
  typedef typename conditional<is_same<__link_pointer, __node_pointer>::value,__base_pointer,__node_pointer>::type  __non_link_pointer;

  __link_pointer __unsafe_link_pointer_cast(__link_pointer __p)
  {
      return __p;
  }

  __link_pointer __unsafe_link_pointer_cast(__non_link_pointer __p)
  {
      return static_cast<__link_pointer>(static_cast<_VoidPtr>(__p));
  }

};

// |    o     |                      |         |
// |    .,---.|---     ,---.,---.,---|,---.    |---.,---.,---.,---.
// |    |`---.|        |   ||   ||   ||---'    |   |,---|`---.|---'
// `---'``---'`---'    `   '`---'`---'`---'    `---'`---^`---'`---'

template <class _Tp, class _VoidPtr>
struct __list_node_base
{
    typedef __list_node_pointer_traits<_Tp, _VoidPtr>   _NodeTraits;
    typedef typename _NodeTraits::__node_pointer        __node_pointer;
    typedef typename _NodeTraits::__base_pointer        __base_pointer;
    typedef typename _NodeTraits::__link_pointer        __link_pointer;

    __link_pointer __prev_;
    __link_pointer __next_;

    __list_node_base() : __prev_(_NodeTraits::__unsafe_link_pointer_cast(__self())), __next_(_NodeTraits::__unsafe_link_pointer_cast(__self()))
    {}
    
    __base_pointer __self()
    {
        return pointer_traits<__base_pointer>::pointer_to(*this);
    }

    __node_pointer __as_node()
    {
        return static_cast<__node_pointer>(__self());
    }
};

// |    o     |                      |
// |    .,---.|---     ,---.,---.,---|,---.
// |    |`---.|        |   ||   ||   ||---'
// `---'``---'`---'    `   '`---'`---'`---'

template <class _Tp, class _VoidPtr>
struct __list_node : public __list_node_base<_Tp, _VoidPtr>
{
    _Tp __value_;

    typedef __list_node_base<_Tp, _VoidPtr>     __base;
    typedef typename __base::__link_pointer     __link_pointer;

    __link_pointer __as_link()
    {
        return static_cast<__link_pointer>(__base::__self());
    }
};

template <class _Tp, class _Alloc = allocator<_Tp> >    class _LIBCPP_TEMPLATE_VIS list;
template <class _Tp, class _Alloc>                      class __list_imp;
template <class _Tp, class _VoidPtr>                    class _LIBCPP_TEMPLATE_VIS __list_const_iterator;

// |    o     |        o|                   |
// |    .,---.|---     .|--- ,---.,---.,---.|--- ,---.,---.
// |    |`---.|        ||    |---'|    ,---||    |   ||
// `---'``---'`---'    ``---'`---'`    `---^`---'`---'`

template <class _Tp, class _VoidPtr>
class _LIBCPP_TEMPLATE_VIS __list_iterator
{
    typedef __list_node_pointer_traits<_Tp, _VoidPtr> _NodeTraits;
    typedef typename _NodeTraits::__link_pointer __link_pointer;

    __link_pointer __ptr_;

    explicit __list_iterator(__link_pointer __p) _NOEXCEPT : __ptr_(__p)
    {}

    template<class, class> friend class list;
    template<class, class> friend class __list_imp;
    template<class, class> friend class __list_const_iterator;

public:
    typedef bidirectional_iterator_tag       iterator_category;
    typedef _Tp                              value_type;
    typedef value_type&                      reference;
    typedef typename __rebind_pointer<_VoidPtr, value_type>::type pointer;
    typedef typename pointer_traits<pointer>::difference_type difference_type;

    __list_iterator() _NOEXCEPT : __ptr_(nullptr)
    {}

    reference operator*() const
    {
        return __ptr_->__as_node()->__value_;
    }

    pointer operator->() const
    {
        return pointer_traits<pointer>::pointer_to(__ptr_->__as_node()->__value_);
    }

    __list_iterator& operator++()
    {
        __ptr_ = __ptr_->__next_;
        return *this;
    }

    __list_iterator operator++(int)
    {
        __list_iterator __t(*this);
        ++(*this);
        return __t;
    }

    __list_iterator& operator--()
    {
        __ptr_ = __ptr_->__prev_;
        return *this;
    }

    __list_iterator operator--(int)
    {
        __list_iterator __t(*this);
        --(*this);
        return __t;
    }

    friend bool operator==(const __list_iterator& __x, const __list_iterator& __y)
    {
        return __x.__ptr_ == __y.__ptr_;
    }
    
    friend bool operator!=(const __list_iterator& __x, const __list_iterator& __y)
    {
        return !(__x == __y);
    }
};

// |    o     |                            |        o|                   |
// |    .,---.|---     ,---.,---.,---.,---.|---     .|--- ,---.,---.,---.|--- ,---.,---.
// |    |`---.|        |    |   ||   |`---.|        ||    |---'|    ,---||    |   ||
// `---'``---'`---'    `---'`---'`   '`---'`---'    ``---'`---'`    `---^`---'`---'`

template <class _Tp, class _VoidPtr>
class _LIBCPP_TEMPLATE_VIS __list_const_iterator
{
    typedef __list_node_pointer_traits<_Tp, _VoidPtr> _NodeTraits;
    typedef typename _NodeTraits::__link_pointer __link_pointer;

    __link_pointer __ptr_;

    _LIBCPP_INLINE_VISIBILITY
    explicit __list_const_iterator(__link_pointer __p) _NOEXCEPT : __ptr_(__p)
{}

    template<class, class> friend class list;
    template<class, class> friend class __list_imp;

public:
    typedef bidirectional_iterator_tag       iterator_category;
    typedef _Tp                              value_type;
    typedef const value_type&                reference;
    typedef typename __rebind_pointer<_VoidPtr, const value_type>::type pointer;
    typedef typename pointer_traits<pointer>::difference_type difference_type;

    __list_const_iterator() _NOEXCEPT : __ptr_(nullptr)
{}
    __list_const_iterator(const __list_iterator<_Tp, _VoidPtr>& __p) _NOEXCEPT : __ptr_(__p.__ptr_)
{}

    reference operator*() const {
        return __ptr_->__as_node()->__value_;
    }

    pointer operator->() const {
        return pointer_traits<pointer>::pointer_to(__ptr_->__as_node()->__value_);
    }

    __list_const_iterator& operator++()
{
        __ptr_ = __ptr_->__next_;
        return *this;
    }

    __list_const_iterator operator++(int)
{
        __list_const_iterator __t(*this);
        ++(*this);
        return __t;
    }

    __list_const_iterator& operator--()
{
        __ptr_ = __ptr_->__prev_;
        return *this;
    }

    __list_const_iterator operator--(int)
{
        __list_const_iterator __t(*this);
        --(*this);
        return __t;
    }

    friend bool operator==(const __list_const_iterator& __x, const __list_const_iterator& __y)
{
        return __x.__ptr_ == __y.__ptr_;
    }
    
    friend bool operator!=(const __list_const_iterator& __x, const __list_const_iterator& __y)
{
        return !(__x == __y);
    }
};

// |    o     |        o
// |    .,---.|---     .,-.-.,---.
// |    |`---.|        || | ||   |
// `---'``---'`---'    `` ' '|---'
//                           |

template <class _Tp, class _Alloc>
class __list_imp
{

    __list_imp(const __list_imp&);
    __list_imp& operator=(const __list_imp&)

public:
    typedef _Alloc                                                  allocator_type;
    typedef allocator_traits<allocator_type>                        __alloc_traits;
    typedef typename __alloc_traits::size_type                      size_type;

protected:
    typedef _Tp                                                     value_type;
    typedef typename __alloc_traits::void_pointer                   __void_pointer;
    typedef __list_iterator<value_type, __void_pointer>             iterator;
    typedef __list_const_iterator<value_type, __void_pointer>       const_iterator;
    typedef __list_node_base<value_type, __void_pointer>            __node_base;
    typedef __list_node<value_type, __void_pointer>                 __node;
    typedef typename __rebind_alloc_helper<__alloc_traits, __node>::type __node_allocator;
    typedef allocator_traits<__node_allocator>                       __node_alloc_traits;
    typedef typename __node_alloc_traits::pointer                    __node_pointer;
    typedef typename __node_alloc_traits::pointer                    __node_const_pointer;
    typedef __list_node_pointer_traits<value_type, __void_pointer> __node_pointer_traits;
    typedef typename __node_pointer_traits::__link_pointer __link_pointer;
    typedef __link_pointer __link_const_pointer;
    typedef typename __alloc_traits::pointer                         pointer;
    typedef typename __alloc_traits::const_pointer                   const_pointer;
    typedef typename __alloc_traits::difference_type                 difference_type;

    typedef typename __rebind_alloc_helper<__alloc_traits, __node_base>::type __node_base_allocator;
    typedef typename allocator_traits<__node_base_allocator>::pointer __node_base_pointer;
    static_assert((!is_same<allocator_type, __node_allocator>::value),
                  "internal allocator type must differ from user-specified "
                  "type; otherwise overload resolution breaks");

    __node_base __end_;
    __compressed_pair<size_type, __node_allocator> __size_alloc_;

    __link_pointer __end_as_link() const _NOEXCEPT
    {
        return __node_pointer_traits::__unsafe_link_pointer_cast(const_cast<__node_base&>(__end_).__self());
    }

    size_type& __sz() _NOEXCEPT {return __size_alloc_.first();}

    const size_type& __sz() const _NOEXCEPT
    {
        return __size_alloc_.first();
    }

    __node_allocator& __node_alloc() _NOEXCEPT
    {
        return __size_alloc_.second();
    }

    const __node_allocator& __node_alloc() const _NOEXCEPT
    {
        return __size_alloc_.second();
    }

    size_type __node_alloc_max_size() const _NOEXCEPT
    {
        return __node_alloc_traits::max_size(__node_alloc());
    }

    static void __unlink_nodes(__link_pointer __f, __link_pointer __l) _NOEXCEPT;

    __list_imp() _NOEXCEPT_(is_nothrow_default_constructible<__node_allocator>::value);
    __list_imp(const allocator_type& __a);
    __list_imp(const __node_allocator& __a);
#ifndef _LIBCPP_CXX03_LANG
    __list_imp(__node_allocator&& __a) _NOEXCEPT;
#endif
    ~__list_imp();
    void clear() _NOEXCEPT;
    bool empty() const _NOEXCEPT {return __sz() == 0;}

    iterator begin() _NOEXCEPT
    {
        return iterator(__end_.__next_);
    }

    const_iterator begin() const  _NOEXCEPT
    {
        return const_iterator(__end_.__next_);
    }

    iterator end() _NOEXCEPT
    {
        return iterator(__end_as_link());
    }

    const_iterator end() const _NOEXCEPT
    {
        return const_iterator(__end_as_link());
    }

    void swap(__list_imp& __c) _NOEXCEPT_(!__alloc_traits::propagate_on_container_swap::value || __is_nothrow_swappable<allocator_type>::value);

    void __copy_assign_alloc(const __list_imp& __c)
    {
        __copy_assign_alloc(__c, integral_constant<bool, __node_alloc_traits::propagate_on_container_copy_assignment::value>());
    }

    void __move_assign_alloc(__list_imp& __c) _NOEXCEPT_(!__node_alloc_traits::propagate_on_container_move_assignment::value || is_nothrow_move_assignable<__node_allocator>::value)
    {
        __move_assign_alloc(__c, integral_constant<bool, __node_alloc_traits::propagate_on_container_move_assignment::value>());
    }

private:

    void __copy_assign_alloc(const __list_imp& __c, true_type)
    {
        if (__node_alloc() != __c.__node_alloc())
            clear();
        __node_alloc() = __c.__node_alloc();
    }

    void __copy_assign_alloc(const __list_imp&, false_type)
    {}

    void __move_assign_alloc(__list_imp& __c, true_type) _NOEXCEPT_(is_nothrow_move_assignable<__node_allocator>::value)
    {
        __node_alloc() = _VSTD::move(__c.__node_alloc());
    }

    void __move_assign_alloc(__list_imp&, false_type) _NOEXCEPT
    {}

    void __invalidate_all_iterators()
    {}
};

// o     |    o              |    o     |        o
// .,---.|    .,---.,---.    |    .,---.|---     .,-.-.,---.
// ||   ||    ||   ||---'    |    |`---.|        || | ||   |
// ``   '`---'``   '`---'    `---'``---'`---'    `` ' '|---'
//                                                     |

// Unlink nodes [__f, __l]
template <class _Tp, class _Alloc>
inline
void
__list_imp<_Tp, _Alloc>::__unlink_nodes(__link_pointer __f, __link_pointer __l)
    _NOEXCEPT
{
    __f->__prev_->__next_ = __l->__next_;
    __l->__next_->__prev_ = __f->__prev_;
}

template <class _Tp, class _Alloc>
inline
__list_imp<_Tp, _Alloc>::__list_imp()
        _NOEXCEPT_(is_nothrow_default_constructible<__node_allocator>::value)
    : __size_alloc_(0, __default_init_tag())
{}

template <class _Tp, class _Alloc>
inline
__list_imp<_Tp, _Alloc>::__list_imp(const allocator_type& __a)
    : __size_alloc_(0, __node_allocator(__a))
{}

template <class _Tp, class _Alloc>
inline __list_imp<_Tp, _Alloc>::__list_imp(const __node_allocator& __a)
    : __size_alloc_(0, __a)
{}

#ifndef _LIBCPP_CXX03_LANG
template <class _Tp, class _Alloc>
inline __list_imp<_Tp, _Alloc>::__list_imp(__node_allocator&& __a) _NOEXCEPT
    : __size_alloc_(0, std::move(__a))
{}
#endif

template <class _Tp, class _Alloc>
__list_imp<_Tp, _Alloc>::~__list_imp()
{
  clear();
}

template <class _Tp, class _Alloc>
void
__list_imp<_Tp, _Alloc>::clear() _NOEXCEPT
{
    if (!empty())
    {
        __node_allocator& __na = __node_alloc();
        __link_pointer __f = __end_.__next_;
        __link_pointer __l = __end_as_link();
        __unlink_nodes(__f, __l->__prev_);
        __sz() = 0;
        while (__f != __l)
        {
            __node_pointer __np = __f->__as_node();
            __f = __f->__next_;
            __node_alloc_traits::destroy(__na, _VSTD::addressof(__np->__value_));
            __node_alloc_traits::deallocate(__na, __np, 1);
        }
        __invalidate_all_iterators();
    }
}

template <class _Tp, class _Alloc>
void
__list_imp<_Tp, _Alloc>::swap(__list_imp& __c)
        _NOEXCEPT_(!__alloc_traits::propagate_on_container_swap::value ||
                    __is_nothrow_swappable<allocator_type>::value)
{
    _LIBCPP_ASSERT(__alloc_traits::propagate_on_container_swap::value ||
                   this->__node_alloc() == __c.__node_alloc(),
                   "list::swap: Either propagate_on_container_swap must be true"
                   " or the allocators must compare equal");
    using _VSTD::swap;
    __swap_allocator(__node_alloc(), __c.__node_alloc());
    swap(__sz(), __c.__sz());
    swap(__end_, __c.__end_);
    if (__sz() == 0)
        __end_.__next_ = __end_.__prev_ = __end_as_link();
    else
        __end_.__prev_->__next_ = __end_.__next_->__prev_ = __end_as_link();
    if (__c.__sz() == 0)
        __c.__end_.__next_ = __c.__end_.__prev_ = __c.__end_as_link();
    else
        __c.__end_.__prev_->__next_ = __c.__end_.__next_->__prev_ = __c.__end_as_link();
}

// |    o     |
// |    .,---.|---
// |    |`---.|
// `---'``---'`---'

template <class _Tp, class _Alloc /*= allocator<_Tp>*/>
class _LIBCPP_TEMPLATE_VIS list
    : private __list_imp<_Tp, _Alloc>
{
    typedef __list_imp<_Tp, _Alloc> base;
    typedef typename base::__node              __node;
    typedef typename base::__node_allocator    __node_allocator;
    typedef typename base::__node_pointer      __node_pointer;
    typedef typename base::__node_alloc_traits __node_alloc_traits;
    typedef typename base::__node_base         __node_base;
    typedef typename base::__node_base_pointer __node_base_pointer;
    typedef typename base::__link_pointer __link_pointer;

public:
    typedef _Tp                                      value_type;
    typedef _Alloc                                   allocator_type;
    static_assert((is_same<value_type, typename allocator_type::value_type>::value),
                  "Invalid allocator::value_type");
    typedef value_type&                              reference;
    typedef const value_type&                        const_reference;
    typedef typename base::pointer                   pointer;
    typedef typename base::const_pointer             const_pointer;
    typedef typename base::size_type                 size_type;
    typedef typename base::difference_type           difference_type;
    typedef typename base::iterator                  iterator;
    typedef typename base::const_iterator            const_iterator;
    typedef _VSTD::reverse_iterator<iterator>         reverse_iterator;
    typedef _VSTD::reverse_iterator<const_iterator>   const_reverse_iterator;
    typedef void                                     __remove_return_type;


    list()
        _NOEXCEPT_(is_nothrow_default_constructible<__node_allocator>::value)
{}

    explicit list(const allocator_type& __a) : base(__a)
{}

    explicit list(size_type __n);

    list(size_type __n, const value_type& __x);

    list(size_type __n, const value_type& __x, const allocator_type& __a);

    template <class _InpIter>
        list(_InpIter __f, _InpIter __l, typename enable_if<__is_cpp17_input_iterator<_InpIter>::value>::type* = 0);
    template <class _InpIter>
        list(_InpIter __f, _InpIter __l, const allocator_type& __a, typename enable_if<__is_cpp17_input_iterator<_InpIter>::value>::type* = 0);

    list(const list& __c);
    list(const list& __c, const allocator_type& __a);

    list& operator=(const list& __c);

#ifndef _LIBCPP_CXX03_LANG

    list(initializer_list<value_type> __il);

    list(initializer_list<value_type> __il, const allocator_type& __a);

    list(list&& __c) _NOEXCEPT_(is_nothrow_move_constructible<__node_allocator>::value);

    list(list&& __c, const allocator_type& __a);

    list& operator=(list&& __c) _NOEXCEPT_(__node_alloc_traits::propagate_on_container_move_assignment::value && is_nothrow_move_assignable<__node_allocator>::value);

    list& operator=(initializer_list<value_type> __il)
{
        assign(__il.begin(), __il.end()); return *this;
    }

    void assign(initializer_list<value_type> __il)
{
        assign(__il.begin(), __il.end());
    }
#endif  // _LIBCPP_CXX03_LANG

    template <class _InpIter>
        void assign(_InpIter __f, _InpIter __l, typename enable_if<__is_cpp17_input_iterator<_InpIter>::value>::type* = 0);
    
    void assign(size_type __n, const value_type& __x);

    allocator_type get_allocator() const _NOEXCEPT;

    size_type size() const _NOEXCEPT     {return base::__sz();}
    
    bool empty() const _NOEXCEPT         {return base::empty();}
    
    size_type max_size() const _NOEXCEPT {
        return std::min<size_type>(base::__node_alloc_max_size(), numeric_limits<difference_type >::max());
    }

          iterator begin() _NOEXCEPT        {return base::begin();}
    const_iterator begin()  const _NOEXCEPT {return base::begin();}
          iterator end() _NOEXCEPT          {return base::end();}
    const_iterator end()    const _NOEXCEPT {return base::end();}
    const_iterator cbegin() const _NOEXCEPT {return base::begin();}
    const_iterator cend()   const _NOEXCEPT {return base::end();}

          reverse_iterator rbegin() _NOEXCEPT        {return       reverse_iterator(end());}
    const_reverse_iterator rbegin()  const _NOEXCEPT {return const_reverse_iterator(end());}
          reverse_iterator rend() _NOEXCEPT          {return       reverse_iterator(begin());}
    const_reverse_iterator rend()    const _NOEXCEPT {return const_reverse_iterator(begin());}
    const_reverse_iterator crbegin() const _NOEXCEPT {return const_reverse_iterator(end());}
    const_reverse_iterator crend()   const _NOEXCEPT {return const_reverse_iterator(begin());}

    reference front()
{
        _LIBCPP_ASSERT(!empty(), "list::front called on empty list");
        return base::__end_.__next_->__as_node()->__value_;
    }

    const_reference front() const {
        _LIBCPP_ASSERT(!empty(), "list::front called on empty list");
        return base::__end_.__next_->__as_node()->__value_;
    }

    reference back()
{
        _LIBCPP_ASSERT(!empty(), "list::back called on empty list");
        return base::__end_.__prev_->__as_node()->__value_;
    }

    const_reference back() const {
        _LIBCPP_ASSERT(!empty(), "list::back called on empty list");
        return base::__end_.__prev_->__as_node()->__value_;
    }

#ifndef _LIBCPP_CXX03_LANG
    void push_front(value_type&& __x);
    void push_back(value_type&& __x);

    template <class... _Args>
       void      emplace_front(_Args&&... __args);
    template <class... _Args>
       void       emplace_back(_Args&&... __args);
    template <class... _Args>
        iterator emplace(const_iterator __p, _Args&&... __args);

    iterator insert(const_iterator __p, value_type&& __x);

    iterator insert(const_iterator __p, initializer_list<value_type> __il)
{
        return insert(__p, __il.begin(), __il.end());
    }
#endif  // _LIBCPP_CXX03_LANG

    void push_front(const value_type& __x);
    void push_back(const value_type& __x);

#ifndef _LIBCPP_CXX03_LANG
    template <class _Arg>
    void __emplace_back(_Arg&& __arg)
{ emplace_back(_VSTD::forward<_Arg>(__arg)); }
#else
    void __emplace_back(value_type const& __arg)
{ push_back(__arg); }
#endif

    iterator insert(const_iterator __p, const value_type& __x);
    iterator insert(const_iterator __p, size_type __n, const value_type& __x);
    template <class _InpIter>
    iterator insert(const_iterator __p, _InpIter __f, _InpIter __l, typename enable_if<__is_cpp17_input_iterator<_InpIter>::value>::type* = 0);

    void swap(list& __c) _NOEXCEPT_(!__node_alloc_traits::propagate_on_container_swap::value || __is_nothrow_swappable<__node_allocator>::value)
{
        base::swap(__c);
    }

    void clear() _NOEXCEPT {
        base::clear();
    }

    void pop_front();
    void pop_back();

    iterator erase(const_iterator __p);
    iterator erase(const_iterator __f, const_iterator __l);

    void resize(size_type __n);
    void resize(size_type __n, const value_type& __x);

    void splice(const_iterator __p, list& __c);
#ifndef _LIBCPP_CXX03_LANG
    
    void splice(const_iterator __p, list&& __c)
{
        splice(__p, __c);
    }
    
    void splice(const_iterator __p, list&& __c, const_iterator __i)
{
        splice(__p, __c, __i);
    }
    
    void splice(const_iterator __p, list&& __c, const_iterator __f, const_iterator __l)
{
        splice(__p, __c, __f, __l);
    }

#endif

    void splice(const_iterator __p, list& __c, const_iterator __i);
    void splice(const_iterator __p, list& __c, const_iterator __f, const_iterator __l);

    __remove_return_type remove(const value_type& __x);

    template <class _Pred> __remove_return_type remove_if(_Pred __pred);
    
    __remove_return_type unique()
{
        return unique(__equal_to<value_type>());
    }

    template <class _BinaryPred> __remove_return_type unique(_BinaryPred __binary_pred);
    
    void merge(list& __c);

#ifndef _LIBCPP_CXX03_LANG

    void merge(list&& __c)
{merge(__c);}

    template <class _Comp>
        void merge(list&& __c, _Comp __comp)
{merge(__c, __comp);}

#endif

    template <class _Comp> void merge(list& __c, _Comp __comp);

    void sort();
    template <class _Comp> void sort(_Comp __comp);

    void reverse() _NOEXCEPT;

    bool __invariants() const;

    typedef __allocator_destructor<__node_allocator> __node_destructor;
    typedef unique_ptr<__node, __node_destructor> __hold_pointer;

    __hold_pointer __allocate_node(__node_allocator& __na)
{
        __node_pointer __p = __node_alloc_traits::allocate(__na, 1);
        __p->__prev_ = nullptr;
        return __hold_pointer(__p, __node_destructor(__na, 1));
    }

private:
    static void __link_nodes  (__link_pointer __p, __link_pointer __f, __link_pointer __l);
    void __link_nodes_at_front(__link_pointer __f, __link_pointer __l);
    void __link_nodes_at_back (__link_pointer __f, __link_pointer __l);
    iterator __iterator(size_type __n);
    template <class _Comp> static iterator __sort(iterator __f1, iterator __e2, size_type __n, _Comp& __comp);

    void __move_assign(list& __c, true_type) _NOEXCEPT_(is_nothrow_move_assignable<__node_allocator>::value);
    void __move_assign(list& __c, false_type);
};

//               |    |    o     |
// ,---.,---.,---|    |    .,---.|---
// |---'|   ||   |    |    |`---.|
// `---'`   '`---'    `---'``---'`---'

#ifndef _LIBCPP_HAS_NO_DEDUCTION_GUIDES
template<class _InputIterator, class _Alloc = typename std::allocator<typename iterator_traits<_InputIterator>::value_type>, class = typename enable_if<__is_allocator<_Alloc>::value, void>::type>
list(_InputIterator, _InputIterator)
  -> list<typename iterator_traits<_InputIterator>::value_type, _Alloc>;

template<class _InputIterator, class _Alloc, class = typename enable_if<__is_allocator<_Alloc>::value, void>::type>
list(_InputIterator, _InputIterator, _Alloc)
  -> list<typename iterator_traits<_InputIterator>::value_type, _Alloc>;
#endif

// Link in nodes [__f, __l] just prior to __p
template <class _Tp, class _Alloc>
inline
void
list<_Tp, _Alloc>::__link_nodes(__link_pointer __p, __link_pointer __f, __link_pointer __l)
{
    __p->__prev_->__next_ = __f;
    __f->__prev_ = __p->__prev_;
    __p->__prev_ = __l;
    __l->__next_ = __p;
}

// Link in nodes [__f, __l] at the front of the list
template <class _Tp, class _Alloc>
inline
void
list<_Tp, _Alloc>::__link_nodes_at_front(__link_pointer __f, __link_pointer __l)
{
    __f->__prev_ = base::__end_as_link();
    __l->__next_ = base::__end_.__next_;
    __l->__next_->__prev_ = __l;
    base::__end_.__next_ = __f;
}

// Link in nodes [__f, __l] at the back of the list
template <class _Tp, class _Alloc>
inline
void
list<_Tp, _Alloc>::__link_nodes_at_back(__link_pointer __f, __link_pointer __l)
{
    __l->__next_ = base::__end_as_link();
    __f->__prev_ = base::__end_.__prev_;
    __f->__prev_->__next_ = __f;
    base::__end_.__prev_ = __l;
}


template <class _Tp, class _Alloc>
inline
typename list<_Tp, _Alloc>::iterator
list<_Tp, _Alloc>::__iterator(size_type __n)
{
    return __n <= base::__sz() / 2 ? _VSTD::next(begin(), __n) : _VSTD::prev(end(), base::__sz() - __n);
}

template <class _Tp, class _Alloc>
list<_Tp, _Alloc>::list(size_type __n)
{
    for (; __n > 0; --__n)
#ifndef _LIBCPP_CXX03_LANG
        emplace_back();
#else
        push_back(value_type());
#endif
}

template <class _Tp, class _Alloc>
list<_Tp, _Alloc>::list(size_type __n, const value_type& __x)
{
    for (; __n > 0; --__n)
        push_back(__x);
}

template <class _Tp, class _Alloc>
list<_Tp, _Alloc>::list(size_type __n, const value_type& __x, const allocator_type& __a)
: base(__a)
{
    for (; __n > 0; --__n)
        push_back(__x);
}

template <class _Tp, class _Alloc>
template <class _InpIter>
list<_Tp, _Alloc>::list(_InpIter __f, _InpIter __l, typename enable_if<__is_cpp17_input_iterator<_InpIter>::value>::type*)
{
    for (; __f != __l; ++__f)
        __emplace_back(*__f);
}

template <class _Tp, class _Alloc>
template <class _InpIter>
list<_Tp, _Alloc>::list(_InpIter __f, _InpIter __l, const allocator_type& __a, typename enable_if<__is_cpp17_input_iterator<_InpIter>::value>::type*)
: base(__a)
{
    for (; __f != __l; ++__f)
        __emplace_back(*__f);
}

template <class _Tp, class _Alloc>
list<_Tp, _Alloc>::list(const list& __c)
: base(__node_alloc_traits::select_on_container_copy_construction(__c.__node_alloc()))
{
    for (const_iterator __i = __c.begin(), __e = __c.end(); __i != __e; ++__i)
        push_back(*__i);
}

template <class _Tp, class _Alloc>
list<_Tp, _Alloc>::list(const list& __c, const allocator_type& __a)
: base(__a)
{
    for (const_iterator __i = __c.begin(), __e = __c.end(); __i != __e; ++__i)
        push_back(*__i);
}

#ifndef _LIBCPP_CXX03_LANG

template <class _Tp, class _Alloc>
list<_Tp, _Alloc>::list(initializer_list<value_type> __il, const allocator_type& __a)
: base(__a)
{
    for (typename initializer_list<value_type>::const_iterator __i = __il.begin(), __e = __il.end(); __i != __e; ++__i)
        push_back(*__i);
}

template <class _Tp, class _Alloc>
list<_Tp, _Alloc>::list(initializer_list<value_type> __il)
{
    for (typename initializer_list<value_type>::const_iterator __i = __il.begin(), __e = __il.end(); __i != __e; ++__i)
        push_back(*__i);
}

template <class _Tp, class _Alloc>
inline list<_Tp, _Alloc>::list(list&& __c) _NOEXCEPT_(is_nothrow_move_constructible<__node_allocator>::value)
: base(_VSTD::move(__c.__node_alloc()))
{
    splice(end(), __c);
}

template <class _Tp, class _Alloc>
inline list<_Tp, _Alloc>::list(list&& __c, const allocator_type& __a)
: base(__a)
{
    if (__a == __c.get_allocator())
        splice(end(), __c);
    else
    {
        typedef move_iterator<iterator> _Ip;
        assign(_Ip(__c.begin()), _Ip(__c.end()));
    }
}

template <class _Tp, class _Alloc>
inline list<_Tp, _Alloc>& list<_Tp, _Alloc>::operator=(list&& __c) _NOEXCEPT_(__node_alloc_traits::propagate_on_container_move_assignment::value && is_nothrow_move_assignable<__node_allocator>::value)
{
    __move_assign(__c, integral_constant<bool, __node_alloc_traits::propagate_on_container_move_assignment::value>());
    return *this;
}

template <class _Tp, class _Alloc>
void list<_Tp, _Alloc>::__move_assign(list& __c, false_type)
{
    if (base::__node_alloc() != __c.__node_alloc())
    {
        typedef move_iterator<iterator> _Ip;
        assign(_Ip(__c.begin()), _Ip(__c.end()));
    }
    else
        __move_assign(__c, true_type());
}

template <class _Tp, class _Alloc>
void list<_Tp, _Alloc>::__move_assign(list& __c, true_type) _NOEXCEPT_(is_nothrow_move_assignable<__node_allocator>::value)
{
    clear();
    base::__move_assign_alloc(__c);
    splice(end(), __c);
}

#endif  // _LIBCPP_CXX03_LANG

template <class _Tp, class _Alloc>
inline list<_Tp, _Alloc>& list<_Tp, _Alloc>::operator=(const list& __c)
{
    if (this != &__c)
    {
        base::__copy_assign_alloc(__c);
        assign(__c.begin(), __c.end());
    }
    return *this;
}

template <class _Tp, class _Alloc>
template <class _InpIter>
void list<_Tp, _Alloc>::assign(_InpIter __f, _InpIter __l, typename enable_if<__is_cpp17_input_iterator<_InpIter>::value>::type*)
{
    iterator __i = begin();
    iterator __e = end();
    for (; __f != __l && __i != __e; ++__f, ++__i)
        *__i = *__f;
    if (__i == __e)
        insert(__e, __f, __l);
    else
        erase(__i, __e);
}

template <class _Tp, class _Alloc>
void list<_Tp, _Alloc>::assign(size_type __n, const value_type& __x)
{
    iterator __i = begin();
    iterator __e = end();
    for (; __n > 0 && __i != __e; --__n, ++__i)
        *__i = __x;
    if (__i == __e)
        insert(__e, __n, __x);
    else
        erase(__i, __e);
}

template <class _Tp, class _Alloc>
inline _Alloc list<_Tp, _Alloc>::get_allocator() const _NOEXCEPT
{
    return allocator_type(base::__node_alloc());
}

template <class _Tp, class _Alloc>
typename list<_Tp, _Alloc>::iterator
list<_Tp, _Alloc>::insert(const_iterator __p, const value_type& __x)
{
    __node_allocator& __na = base::__node_alloc();
    __hold_pointer __hold = __allocate_node(__na);
    __node_alloc_traits::construct(__na, _VSTD::addressof(__hold->__value_), __x);
    __link_nodes(__p.__ptr_, __hold->__as_link(), __hold->__as_link());
    ++base::__sz();
    return iterator(__hold.release()->__as_link());
}

template <class _Tp, class _Alloc>
typename list<_Tp, _Alloc>::iterator list<_Tp, _Alloc>::insert(const_iterator __p, size_type __n, const value_type& __x)
{
    iterator __r(__p.__ptr_);
    if (__n > 0)
    {
        size_type __ds = 0;
        __node_allocator& __na = base::__node_alloc();
        __hold_pointer __hold = __allocate_node(__na);
        __node_alloc_traits::construct(__na, _VSTD::addressof(__hold->__value_), __x);
        ++__ds;
        __r = iterator(__hold->__as_link());
        __hold.release();
        iterator __e = __r;
#ifndef _LIBCPP_NO_EXCEPTIONS
        try
        {
#endif  // _LIBCPP_NO_EXCEPTIONS
            for (--__n; __n != 0; --__n, ++__e, ++__ds)
            {
                __hold.reset(__node_alloc_traits::allocate(__na, 1));
                __node_alloc_traits::construct(__na, _VSTD::addressof(__hold->__value_), __x);
                __e.__ptr_->__next_ = __hold->__as_link();
                __hold->__prev_ = __e.__ptr_;
                __hold.release();
            }
#ifndef _LIBCPP_NO_EXCEPTIONS
        }
        catch (...)
        {
            while (true)
            {
                __node_alloc_traits::destroy(__na, _VSTD::addressof(*__e));
                __link_pointer __prev = __e.__ptr_->__prev_;
                __node_alloc_traits::deallocate(__na, __e.__ptr_->__as_node(), 1);
                if (__prev == 0)
                    break;
                __e = iterator(__prev);
            }
            throw;
        }
#endif  // _LIBCPP_NO_EXCEPTIONS
        __link_nodes(__p.__ptr_, __r.__ptr_, __e.__ptr_);
        base::__sz() += __ds;
    }
    return __r;
}

template <class _Tp, class _Alloc>
template <class _InpIter>
typename list<_Tp, _Alloc>::iterator
list<_Tp, _Alloc>::insert(const_iterator __p, _InpIter __f, _InpIter __l, typename enable_if<__is_cpp17_input_iterator<_InpIter>::value>::type*)
{
    iterator __r(__p.__ptr_);
    if (__f != __l)
    {
        size_type __ds = 0;
        __node_allocator& __na = base::__node_alloc();
        __hold_pointer __hold = __allocate_node(__na);
        __node_alloc_traits::construct(__na, _VSTD::addressof(__hold->__value_), *__f);
        ++__ds;
        __r = iterator(__hold.get()->__as_link());
        __hold.release();
        iterator __e = __r;
#ifndef _LIBCPP_NO_EXCEPTIONS
        try
        {
#endif  // _LIBCPP_NO_EXCEPTIONS
            for (++__f; __f != __l; ++__f, (void) ++__e, (void) ++__ds)
            {
                __hold.reset(__node_alloc_traits::allocate(__na, 1));
                __node_alloc_traits::construct(__na, _VSTD::addressof(__hold->__value_), *__f);
                __e.__ptr_->__next_ = __hold.get()->__as_link();
                __hold->__prev_ = __e.__ptr_;
                __hold.release();
            }
#ifndef _LIBCPP_NO_EXCEPTIONS
        }
        catch (...)
        {
            while (true)
            {
                __node_alloc_traits::destroy(__na, _VSTD::addressof(*__e));
                __link_pointer __prev = __e.__ptr_->__prev_;
                __node_alloc_traits::deallocate(__na, __e.__ptr_->__as_node(), 1);
                if (__prev == 0)
                    break;
                __e = iterator(__prev);
            }
            throw;
        }
#endif  // _LIBCPP_NO_EXCEPTIONS
        __link_nodes(__p.__ptr_, __r.__ptr_, __e.__ptr_);
        base::__sz() += __ds;
    }
    return __r;
}

template <class _Tp, class _Alloc>
void
list<_Tp, _Alloc>::push_front(const value_type& __x)
{
    __node_allocator& __na = base::__node_alloc();
    __hold_pointer __hold = __allocate_node(__na);
    __node_alloc_traits::construct(__na, _VSTD::addressof(__hold->__value_), __x);
    __link_pointer __nl = __hold->__as_link();
    __link_nodes_at_front(__nl, __nl);
    ++base::__sz();
    __hold.release();
}

template <class _Tp, class _Alloc>
void
list<_Tp, _Alloc>::push_back(const value_type& __x)
{
    __node_allocator& __na = base::__node_alloc();
    __hold_pointer __hold = __allocate_node(__na);
    __node_alloc_traits::construct(__na, _VSTD::addressof(__hold->__value_), __x);
    __link_nodes_at_back(__hold.get()->__as_link(), __hold.get()->__as_link());
    ++base::__sz();
    __hold.release();
}

#ifndef _LIBCPP_CXX03_LANG

template <class _Tp, class _Alloc>
void
list<_Tp, _Alloc>::push_front(value_type&& __x)
{
    __node_allocator& __na = base::__node_alloc();
    __hold_pointer __hold = __allocate_node(__na);
    __node_alloc_traits::construct(__na, _VSTD::addressof(__hold->__value_), _VSTD::move(__x));
    __link_nodes_at_front(__hold.get()->__as_link(), __hold.get()->__as_link());
    ++base::__sz();
    __hold.release();
}

template <class _Tp, class _Alloc>
void
list<_Tp, _Alloc>::push_back(value_type&& __x)
{
    __node_allocator& __na = base::__node_alloc();
    __hold_pointer __hold = __allocate_node(__na);
    __node_alloc_traits::construct(__na, _VSTD::addressof(__hold->__value_), _VSTD::move(__x));
    __link_nodes_at_back(__hold.get()->__as_link(), __hold.get()->__as_link());
    ++base::__sz();
    __hold.release();
}

template <class _Tp, class _Alloc>
template <class... _Args>
void
list<_Tp, _Alloc>::emplace_front(_Args&&... __args)
{
    __node_allocator& __na = base::__node_alloc();
    __hold_pointer __hold = __allocate_node(__na);
    __node_alloc_traits::construct(__na, _VSTD::addressof(__hold->__value_), _VSTD::forward<_Args>(__args)...);
    __link_nodes_at_front(__hold.get()->__as_link(), __hold.get()->__as_link());
    ++base::__sz();
    __hold.release();
}

template <class _Tp, class _Alloc>
template <class... _Args>
void
list<_Tp, _Alloc>::emplace_back(_Args&&... __args)
{
    __node_allocator& __na = base::__node_alloc();
    __hold_pointer __hold = __allocate_node(__na);
    __node_alloc_traits::construct(__na, _VSTD::addressof(__hold->__value_), _VSTD::forward<_Args>(__args)...);
    __link_pointer __nl = __hold->__as_link();
    __link_nodes_at_back(__nl, __nl);
    ++base::__sz();
    __hold.release();
}

template <class _Tp, class _Alloc>
template <class... _Args>
typename list<_Tp, _Alloc>::iterator
list<_Tp, _Alloc>::emplace(const_iterator __p, _Args&&... __args)
{
    __node_allocator& __na = base::__node_alloc();
    __hold_pointer __hold = __allocate_node(__na);
    __node_alloc_traits::construct(__na, _VSTD::addressof(__hold->__value_), _VSTD::forward<_Args>(__args)...);
    __link_pointer __nl = __hold.get()->__as_link();
    __link_nodes(__p.__ptr_, __nl, __nl);
    ++base::__sz();
    __hold.release();
    return iterator(__nl);
}

template <class _Tp, class _Alloc>
typename list<_Tp, _Alloc>::iterator
list<_Tp, _Alloc>::insert(const_iterator __p, value_type&& __x)
{
    __node_allocator& __na = base::__node_alloc();
    __hold_pointer __hold = __allocate_node(__na);
    __node_alloc_traits::construct(__na, _VSTD::addressof(__hold->__value_), _VSTD::move(__x));
    __link_pointer __nl = __hold->__as_link();
    __link_nodes(__p.__ptr_, __nl, __nl);
    ++base::__sz();
    __hold.release();
    return iterator(__nl);
}

#endif  // _LIBCPP_CXX03_LANG

template <class _Tp, class _Alloc>
void
list<_Tp, _Alloc>::pop_front()
{
    _LIBCPP_ASSERT(!empty(), "list::pop_front() called with empty list");
    __node_allocator& __na = base::__node_alloc();
    __link_pointer __n = base::__end_.__next_;
    base::__unlink_nodes(__n, __n);
    --base::__sz();
    __node_pointer __np = __n->__as_node();
    __node_alloc_traits::destroy(__na, _VSTD::addressof(__np->__value_));
    __node_alloc_traits::deallocate(__na, __np, 1);
}

template <class _Tp, class _Alloc>
void
list<_Tp, _Alloc>::pop_back()
{
    _LIBCPP_ASSERT(!empty(), "list::pop_back() called with empty list");
    __node_allocator& __na = base::__node_alloc();
    __link_pointer __n = base::__end_.__prev_;
    base::__unlink_nodes(__n, __n);
    --base::__sz();
    __node_pointer __np = __n->__as_node();
    __node_alloc_traits::destroy(__na, _VSTD::addressof(__np->__value_));
    __node_alloc_traits::deallocate(__na, __np, 1);
}

template <class _Tp, class _Alloc>
typename list<_Tp, _Alloc>::iterator
list<_Tp, _Alloc>::erase(const_iterator __p)
{
    _LIBCPP_ASSERT(__p != end(),
        "list::erase(iterator) called with a non-dereferenceable iterator");
    __node_allocator& __na = base::__node_alloc();
    __link_pointer __n = __p.__ptr_;
    __link_pointer __r = __n->__next_;
    base::__unlink_nodes(__n, __n);
    --base::__sz();
    __node_pointer __np = __n->__as_node();
    __node_alloc_traits::destroy(__na, _VSTD::addressof(__np->__value_));
    __node_alloc_traits::deallocate(__na, __np, 1);
    return iterator(__r);
}

template <class _Tp, class _Alloc>
typename list<_Tp, _Alloc>::iterator
list<_Tp, _Alloc>::erase(const_iterator __f, const_iterator __l)
{
    if (__f != __l)
    {
        __node_allocator& __na = base::__node_alloc();
        base::__unlink_nodes(__f.__ptr_, __l.__ptr_->__prev_);
        while (__f != __l)
        {
            __link_pointer __n = __f.__ptr_;
            ++__f;
            --base::__sz();
            __node_pointer __np = __n->__as_node();
            __node_alloc_traits::destroy(__na, _VSTD::addressof(__np->__value_));
            __node_alloc_traits::deallocate(__na, __np, 1);
        }
    }
    return iterator(__l.__ptr_);
}

template <class _Tp, class _Alloc>
void
list<_Tp, _Alloc>::resize(size_type __n)
{
    if (__n < base::__sz())
        erase(__iterator(__n), end());
    else if (__n > base::__sz())
    {
        __n -= base::__sz();
        size_type __ds = 0;
        __node_allocator& __na = base::__node_alloc();
        __hold_pointer __hold = __allocate_node(__na);
        __node_alloc_traits::construct(__na, _VSTD::addressof(__hold->__value_));
        ++__ds;
        iterator __r = iterator(__hold.release()->__as_link());
        iterator __e = __r;
#ifndef _LIBCPP_NO_EXCEPTIONS
        try
        {
#endif  // _LIBCPP_NO_EXCEPTIONS
            for (--__n; __n != 0; --__n, ++__e, ++__ds)
            {
                __hold.reset(__node_alloc_traits::allocate(__na, 1));
                __node_alloc_traits::construct(__na, _VSTD::addressof(__hold->__value_));
                __e.__ptr_->__next_ = __hold.get()->__as_link();
                __hold->__prev_ = __e.__ptr_;
                __hold.release();
            }
#ifndef _LIBCPP_NO_EXCEPTIONS
        }
        catch (...)
        {
            while (true)
            {
                __node_alloc_traits::destroy(__na, _VSTD::addressof(*__e));
                __link_pointer __prev = __e.__ptr_->__prev_;
                __node_alloc_traits::deallocate(__na, __e.__ptr_->__as_node(), 1);
                if (__prev == 0)
                    break;
                __e = iterator(__prev);
            }
            throw;
        }
#endif  // _LIBCPP_NO_EXCEPTIONS
        __link_nodes_at_back(__r.__ptr_, __e.__ptr_);
        base::__sz() += __ds;
    }
}

template <class _Tp, class _Alloc>
void
list<_Tp, _Alloc>::resize(size_type __n, const value_type& __x)
{
    if (__n < base::__sz())
        erase(__iterator(__n), end());
    else if (__n > base::__sz())
    {
        __n -= base::__sz();
        size_type __ds = 0;
        __node_allocator& __na = base::__node_alloc();
        __hold_pointer __hold = __allocate_node(__na);
        __node_alloc_traits::construct(__na, _VSTD::addressof(__hold->__value_), __x);
        ++__ds;
        __link_pointer __nl = __hold.release()->__as_link();
        iterator __r = iterator(__nl);
        iterator __e = __r;
#ifndef _LIBCPP_NO_EXCEPTIONS
        try
        {
#endif  // _LIBCPP_NO_EXCEPTIONS
            for (--__n; __n != 0; --__n, ++__e, ++__ds)
            {
                __hold.reset(__node_alloc_traits::allocate(__na, 1));
                __node_alloc_traits::construct(__na, _VSTD::addressof(__hold->__value_), __x);
                __e.__ptr_->__next_ = __hold.get()->__as_link();
                __hold->__prev_ = __e.__ptr_;
                __hold.release();
            }
#ifndef _LIBCPP_NO_EXCEPTIONS
        }
        catch (...)
        {
            while (true)
            {
                __node_alloc_traits::destroy(__na, _VSTD::addressof(*__e));
                __link_pointer __prev = __e.__ptr_->__prev_;
                __node_alloc_traits::deallocate(__na, __e.__ptr_->__as_node(), 1);
                if (__prev == 0)
                    break;
                __e = iterator(__prev);
            }
            throw;
        }
#endif  // _LIBCPP_NO_EXCEPTIONS
        __link_nodes(base::__end_as_link(), __r.__ptr_, __e.__ptr_);
        base::__sz() += __ds;
    }
}

template <class _Tp, class _Alloc>
void
list<_Tp, _Alloc>::splice(const_iterator __p, list& __c)
{
    _LIBCPP_ASSERT(this != &__c,
                   "list::splice(iterator, list) called with this == &list");
    if (!__c.empty())
    {
        __link_pointer __f = __c.__end_.__next_;
        __link_pointer __l = __c.__end_.__prev_;
        base::__unlink_nodes(__f, __l);
        __link_nodes(__p.__ptr_, __f, __l);
        base::__sz() += __c.__sz();
        __c.__sz() = 0;
    }
}

template <class _Tp, class _Alloc>
void
list<_Tp, _Alloc>::splice(const_iterator __p, list& __c, const_iterator __i)
{
    if (__p.__ptr_ != __i.__ptr_ && __p.__ptr_ != __i.__ptr_->__next_)
    {
        __link_pointer __f = __i.__ptr_;
        base::__unlink_nodes(__f, __f);
        __link_nodes(__p.__ptr_, __f, __f);
        --__c.__sz();
        ++base::__sz();
    }
}

template <class _Tp, class _Alloc>
void
list<_Tp, _Alloc>::splice(const_iterator __p, list& __c, const_iterator __f, const_iterator __l)
{
    if (__f != __l)
    {
        __link_pointer __first = __f.__ptr_;
        --__l;
        __link_pointer __last = __l.__ptr_;
        if (this != &__c)
        {
            size_type __s = _VSTD::distance(__f, __l) + 1;
            __c.__sz() -= __s;
            base::__sz() += __s;
        }
        base::__unlink_nodes(__first, __last);
        __link_nodes(__p.__ptr_, __first, __last);
    }
}

template <class _Tp, class _Alloc>
typename list<_Tp, _Alloc>::__remove_return_type
list<_Tp, _Alloc>::remove(const value_type& __x)
{
    list<_Tp, _Alloc> __deleted_nodes(get_allocator()); // collect the nodes we're removing
    for (const_iterator __i = begin(), __e = end(); __i != __e;)
    {
        if (*__i == __x)
        {
            const_iterator __j = _VSTD::next(__i);
            for (; __j != __e && *__j == __x; ++__j)
                ;
            __deleted_nodes.splice(__deleted_nodes.end(), *this, __i, __j);
            __i = __j;
            if (__i != __e)
                ++__i;
        }
        else
            ++__i;
    }

    return (__remove_return_type) __deleted_nodes.size();
}

template <class _Tp, class _Alloc>
template <class _Pred>
typename list<_Tp, _Alloc>::__remove_return_type
list<_Tp, _Alloc>::remove_if(_Pred __pred)
{
    list<_Tp, _Alloc> __deleted_nodes(get_allocator()); // collect the nodes we're removing
    for (iterator __i = begin(), __e = end(); __i != __e;)
    {
        if (__pred(*__i))
        {
            iterator __j = _VSTD::next(__i);
            for (; __j != __e && __pred(*__j); ++__j)
                ;
            __deleted_nodes.splice(__deleted_nodes.end(), *this, __i, __j);
            __i = __j;
            if (__i != __e)
                ++__i;
        }
        else
            ++__i;
    }

    return (__remove_return_type) __deleted_nodes.size();
}

template <class _Tp, class _Alloc>
template <class _BinaryPred>
typename list<_Tp, _Alloc>::__remove_return_type
list<_Tp, _Alloc>::unique(_BinaryPred __binary_pred)
{
    list<_Tp, _Alloc> __deleted_nodes(get_allocator()); // collect the nodes we're removing
    for (iterator __i = begin(), __e = end(); __i != __e;)
    {
        iterator __j = _VSTD::next(__i);
        for (; __j != __e && __binary_pred(*__i, *__j); ++__j)
            ;
        if (++__i != __j)
        {
            __deleted_nodes.splice(__deleted_nodes.end(), *this, __i, __j);
            __i = __j;
        }
    }

    return (__remove_return_type) __deleted_nodes.size();
}

template <class _Tp, class _Alloc>
inline
void
list<_Tp, _Alloc>::merge(list& __c)
{
    merge(__c, __less<value_type>());
}

template <class _Tp, class _Alloc>
template <class _Comp>
void
list<_Tp, _Alloc>::merge(list& __c, _Comp __comp)
{
    if (this != _VSTD::addressof(__c))
    {
        iterator __f1 = begin();
        iterator __e1 = end();
        iterator __f2 = __c.begin();
        iterator __e2 = __c.end();
        while (__f1 != __e1 && __f2 != __e2)
        {
            if (__comp(*__f2, *__f1))
            {
                size_type __ds = 1;
                iterator __m2 = _VSTD::next(__f2);
                for (; __m2 != __e2 && __comp(*__m2, *__f1); ++__m2, ++__ds)
                    ;
                base::__sz() += __ds;
                __c.__sz() -= __ds;
                __link_pointer __f = __f2.__ptr_;
                __link_pointer __l = __m2.__ptr_->__prev_;
                __f2 = __m2;
                base::__unlink_nodes(__f, __l);
                __m2 = _VSTD::next(__f1);
                __link_nodes(__f1.__ptr_, __f, __l);
                __f1 = __m2;
            }
            else
                ++__f1;
        }
        splice(__e1, __c);
    }
}

template <class _Tp, class _Alloc>
inline
void
list<_Tp, _Alloc>::sort()
{
    sort(__less<value_type>());
}

template <class _Tp, class _Alloc>
template <class _Comp>
inline
void
list<_Tp, _Alloc>::sort(_Comp __comp)
{
    __sort(begin(), end(), base::__sz(), __comp);
}

template <class _Tp, class _Alloc>
template <class _Comp>
typename list<_Tp, _Alloc>::iterator
list<_Tp, _Alloc>::__sort(iterator __f1, iterator __e2, size_type __n, _Comp& __comp)
{
    switch (__n)
    {
    case 0:
    case 1:
        return __f1;
    case 2:
        if (__comp(*--__e2, *__f1))
        {
            __link_pointer __f = __e2.__ptr_;
            base::__unlink_nodes(__f, __f);
            __link_nodes(__f1.__ptr_, __f, __f);
            return __e2;
        }
        return __f1;
    }
    size_type __n2 = __n / 2;
    iterator __e1 = _VSTD::next(__f1, __n2);
    iterator  __r = __f1 = __sort(__f1, __e1, __n2, __comp);
    iterator __f2 = __e1 = __sort(__e1, __e2, __n - __n2, __comp);
    if (__comp(*__f2, *__f1))
    {
        iterator __m2 = _VSTD::next(__f2);
        for (; __m2 != __e2 && __comp(*__m2, *__f1); ++__m2)
            ;
        __link_pointer __f = __f2.__ptr_;
        __link_pointer __l = __m2.__ptr_->__prev_;
        __r = __f2;
        __e1 = __f2 = __m2;
        base::__unlink_nodes(__f, __l);
        __m2 = _VSTD::next(__f1);
        __link_nodes(__f1.__ptr_, __f, __l);
        __f1 = __m2;
    }
    else
        ++__f1;
    while (__f1 != __e1 && __f2 != __e2)
    {
        if (__comp(*__f2, *__f1))
        {
            iterator __m2 = _VSTD::next(__f2);
            for (; __m2 != __e2 && __comp(*__m2, *__f1); ++__m2)
                ;
            __link_pointer __f = __f2.__ptr_;
            __link_pointer __l = __m2.__ptr_->__prev_;
            if (__e1 == __f2)
                __e1 = __m2;
            __f2 = __m2;
            base::__unlink_nodes(__f, __l);
            __m2 = _VSTD::next(__f1);
            __link_nodes(__f1.__ptr_, __f, __l);
            __f1 = __m2;
        }
        else
            ++__f1;
    }
    return __r;
}

template <class _Tp, class _Alloc>
void
list<_Tp, _Alloc>::reverse() _NOEXCEPT
{
    if (base::__sz() > 1)
    {
        iterator __e = end();
        for (iterator __i = begin(); __i.__ptr_ != __e.__ptr_;)
        {
            _VSTD::swap(__i.__ptr_->__prev_, __i.__ptr_->__next_);
            __i.__ptr_ = __i.__ptr_->__prev_;
        }
        _VSTD::swap(__e.__ptr_->__prev_, __e.__ptr_->__next_);
    }
}

template <class _Tp, class _Alloc>
bool
list<_Tp, _Alloc>::__invariants() const
{
    return size() == _VSTD::distance(begin(), end());
}

template <class _Tp, class _Alloc>
inline _LIBCPP_INLINE_VISIBILITY
bool
operator==(const list<_Tp, _Alloc>& __x, const list<_Tp, _Alloc>& __y)
{
    return __x.size() == __y.size() && _VSTD::equal(__x.begin(), __x.end(), __y.begin());
}

template <class _Tp, class _Alloc>
inline _LIBCPP_INLINE_VISIBILITY
bool
operator< (const list<_Tp, _Alloc>& __x, const list<_Tp, _Alloc>& __y)
{
    return _VSTD::lexicographical_compare(__x.begin(), __x.end(), __y.begin(), __y.end());
}

template <class _Tp, class _Alloc>
inline _LIBCPP_INLINE_VISIBILITY
bool
operator!=(const list<_Tp, _Alloc>& __x, const list<_Tp, _Alloc>& __y)
{
    return !(__x == __y);
}

template <class _Tp, class _Alloc>
inline _LIBCPP_INLINE_VISIBILITY
bool
operator> (const list<_Tp, _Alloc>& __x, const list<_Tp, _Alloc>& __y)
{
    return __y < __x;
}

template <class _Tp, class _Alloc>
inline _LIBCPP_INLINE_VISIBILITY
bool
operator>=(const list<_Tp, _Alloc>& __x, const list<_Tp, _Alloc>& __y)
{
    return !(__x < __y);
}

template <class _Tp, class _Alloc>
inline _LIBCPP_INLINE_VISIBILITY
bool
operator<=(const list<_Tp, _Alloc>& __x, const list<_Tp, _Alloc>& __y)
{
    return !(__y < __x);
}

template <class _Tp, class _Alloc>
inline _LIBCPP_INLINE_VISIBILITY
void
swap(list<_Tp, _Alloc>& __x, list<_Tp, _Alloc>& __y)
    _NOEXCEPT_(_NOEXCEPT_(__x.swap(__y)))
{
    __x.swap(__y);
}

_LIBCPP_END_NAMESPACE_STD

_LIBCPP_POP_MACROS

#endif  // _LIBCPP_LIST
