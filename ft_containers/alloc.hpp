// default allocator template allocator
#ifndef FT_ALLOC_HPP
# define FT_ALLOC_HPP
# include <limits>
# include <iostream> // size_t

namespace ft {
    template <class T> class allocator;
};

template <class T>
class ft::allocator {
public:
    // members
    typedef T               value_type;
    typedef T*              pointer;
    typedef T&              reference;
    typedef const T*        const_pointer;
    typedef const T&        const_reference;
    typedef size_t          size_type;
    typedef std::ptrdiff_t  difference_type;
    template <class U>      struct rebind {
        typedef allocator<U> other;
    };

    // constructor that do nothing
    allocator() throw() {}
    allocator (const allocator& alloc) throw() { static_cast<void>(alloc); }
    template <class U>
    allocator (const allocator<U>& alloc) throw() { static_cast<void>(alloc); }

    // destructor that does nothing
    ~allocator () throw() {}

    // address
    pointer address ( reference x ) const { return &x; }
    const_pointer address ( const_reference x ) const { return &x; }

    // allocate
    pointer allocate (size_type n, const_pointer hint=0) {
        static_cast<void> (hint);
        pointer tmp = (::operator new(n * sizeof(value_type)));
        if (tmp == 0) {
            throw std::bad_alloc();
        }
        return tmp;
    }

    // deallocate
    void deallocate (pointer p, size_type n) {
        ::operator delete(p, n);
    }

    size_type max_size() const throw() {
        return (std::numeric_limits<unsigned int>::max() / sizeof(value_type));
    }

    void construct ( pointer p, const_reference val ) {
        new ((void*)p) value_type (val);
    }

    void destroy (pointer p) {
        p->~value_type();
    }
};

template <>
class ft::allocator<void> {
public:
    typedef void*           pointer;
    typedef const void*     const_pointer;
    typedef void            value_type;
    template <class U>      struct rebind {
        typedef allocator<U> other;
    };
};

#endif
