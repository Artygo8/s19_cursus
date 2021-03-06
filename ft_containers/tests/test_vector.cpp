/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 12:00:01 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/28 12:00:01 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <vector>
#include <math.h>
#include <iostream>
#include "test.hpp"


void test_vector()
{

    TITLE_MGN("                _             ");
    TITLE_MGN("__   _____  ___| |_ ___  _ __ ");
    TITLE_MGN("\\ \\ / / _ \\/ __| __/ _ \\| '__|");
    TITLE_MGN(" \\ V /  __/ (__| || (_) | |   ");
    TITLE_MGN("  \\_/ \\___|\\___|\\__\\___/|_|   ");
    TITLE_MGN("                              ");

    TITLE_RED("__VECTOR_CONSTRUCTORS__");
    {
        TITLE_GRN("std");
          // constructors used in the same order as described above:
        std::vector<int> first;                                // empty vector of ints
        std::vector<int> second (4,100);                       // four ints with value 100
        std::vector<int> third (second.begin(),second.end());  // iterating through second
        std::vector<int> fourth (third);                       // a copy of third

        // the iterator constructor can also be used to construct from arrays:
        int myints[] = {16,2,77,29};
        std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

        std::cout << "The contents of fifth are:";
        for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
          std::cout << ' ' << *it;
        std::cout << '\n';

    }
    {
        TITLE_GRN("ft");
          // constructors used in the same order as described above:
        ft::Vector<int> first;                                // empty vector of ints
        ft::Vector<int> second (static_cast<size_t>(4),100);                       // four ints with value 100
        ft::Vector<int> third (second.begin(),second.end());  // iterating through second
        ft::Vector<int> fourth (third);                       // a copy of third
        
        // the iterator constructor can also be used to construct from arrays:
        int myints[] = {16,2,77,29};
        ft::Vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
        
        std::cout << "The contents of fifth are:";
        for (ft::Vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
          std::cout << ' ' << *it;
        std::cout << '\n';
    }


    TITLE_RED("__VECTOR_ASSINGNMENT__");
    {
        TITLE_GRN("std");
        std::vector<int> foo (static_cast<size_t>(3),0);
        std::vector<int> bar (static_cast<size_t>(5),0);

        bar = foo;
        foo = std::vector<int>();

        std::cout << "Size of foo: " << int(foo.size()) << '\n';
        std::cout << "Size of bar: " << int(bar.size()) << '\n';
    }
    {
        TITLE_GRN("ft");
        ft::Vector<int> foo (static_cast<size_t>(3),0);
        ft::Vector<int> bar (static_cast<size_t>(5),0);

        bar = foo;
        foo = ft::Vector<int>();

        std::cout << "Size of foo: " << int(foo.size()) << '\n';
        std::cout << "Size of bar: " << int(bar.size()) << '\n';
    }


    TITLE_RED("__BEGIN_END__");
    {
        TITLE_GRN("std");
        std::vector<int> myvector;
        for (int i=1; i<=5; i++) myvector.push_back(i);

        std::cout << "myvector contains:";
        for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
          std::cout << ' ' << *it;
        std::cout << '\n';
    }
    {
        TITLE_GRN("ft");
        ft::Vector<int> myvector;
        for (int i=1; i<=5; i++) myvector.push_back(i);

        std::cout << "myvector contains:";
        for (ft::Vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
          std::cout << ' ' << *it;
        std::cout << '\n';
    }

    TITLE_RED("__RBEGIN_REND__");
    {
        TITLE_GRN("std");
        std::vector<int> myvector (5);  // 5 default-constructed ints

        int i=0;

        std::vector<int>::reverse_iterator rit = myvector.rbegin();
        for (; rit!= myvector.rend(); ++rit)
            * rit = ++i;

        std::cout << "myvector contains:";
        for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
    }
    {
        TITLE_GRN("ft");
        ft::Vector<int> myvector (5);  // 5 default-constructed ints

        int i=0;

        ft::Vector<int>::reverse_iterator rit = myvector.rbegin();
        for (; rit!= myvector.rend(); ++rit)
            * rit = ++i;

        std::cout << "myvector contains:";
        for (ft::Vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
    }


    TITLE_RED("__SIZE__");
    {
        TITLE_GRN("std");
        std::vector<int> myints;
        std::cout << "0. size: " << myints.size() << '\n';

        for (int i=0; i<10; i++) myints.push_back(i);
        std::cout << "1. size: " << myints.size() << '\n';

        myints.insert (myints.end(),10,100);
        std::cout << "2. size: " << myints.size() << '\n';

        myints.pop_back();
        std::cout << "3. size: " << myints.size() << '\n';
    }
    {
        TITLE_GRN("ft");
        ft::Vector<int> myints;
        std::cout << "0. size: " << myints.size() << '\n';
        
        for (int i=0; i<10; i++) myints.push_back(i);
        std::cout << "1. size: " << myints.size() << '\n';
        
        myints.insert (myints.end(),static_cast<size_t>(10),100);
        std::cout << "2. size: " << myints.size() << '\n';
        
        myints.pop_back();
        std::cout << "3. size: " << myints.size() << '\n';
    }


    TITLE_RED("__SIZE / CAPACITY / MAX_SIZE__");
    {
        TITLE_GRN("std");
        std::vector<int> myvector;

        // set some content in the vector:
        for (int i=0; i<100; i++) myvector.push_back(i);
        
        std::cout << "size: " << myvector.size() << "\n";
        std::cout << "capacity: " << myvector.capacity() << "\n";
        std::cout << "max_size: " << myvector.max_size() << "\n";
    }
    {
        TITLE_GRN("ft");
        ft::Vector<int> myvector;

        // set some content in the vector:
        for (int i=0; i<100; i++) myvector.push_back(i);
        
        std::cout << "size: " << myvector.size() << "\n";
        std::cout << "capacity: " << myvector.capacity() << "\n";
        std::cout << "max_size: " << myvector.max_size() << "\n";
    }

    TITLE_RED("__RESIZE__");
    {
        TITLE_GRN("std");
        std::vector<int> myvector;

        // set some initial content:
        for (int i=1;i<10;i++) myvector.push_back(i);

        myvector.resize(5);
        myvector.resize(8,100);
        myvector.resize(12);

        std::cout << "myvector contains:";
        for (size_t i=0;i<myvector.size();i++)
            std::cout << ' ' << myvector[i];
        std::cout << '\n';
    }
    {
        TITLE_GRN("ft");
        ft::Vector<int> myvector;

        // set some initial content:
        for (int i=1;i<10;i++) myvector.push_back(i);

        myvector.resize(5);
        myvector.resize(8,100);
        myvector.resize(12);

        std::cout << "myvector contains:";
        for (size_t i=0;i<myvector.size();i++)
            std::cout << ' ' << myvector[i];
        std::cout << '\n';
    }


    TITLE_RED("__RESERVE__");
    {
        TITLE_GRN("std");
        std::vector<int>::size_type sz;

        std::vector<int> foo;
        sz = foo.capacity();
        std::cout << "making foo grow:\n";
        for (int i=0; i<100; ++i) {
            foo.push_back(i);
            if (sz!=foo.capacity()) {
            sz = foo.capacity();
            std::cout << "capacity changed: " << sz << '\n';
            }
        }

        std::vector<int> bar;
        sz = bar.capacity();
        bar.reserve(100);   // this is the only difference with foo above
        std::cout << "making bar grow:\n";
        for (int i=0; i<100; ++i) {
            bar.push_back(i);
            if (sz!=bar.capacity()) {
            sz = bar.capacity();
            std::cout << "capacity changed: " << sz << '\n';
            }
        }
    }
    {
        TITLE_GRN("ft");
        ft::Vector<int>::size_type sz;

        ft::Vector<int> foo;
        sz = foo.capacity();
        std::cout << "making foo grow:\n";
        for (int i=0; i<100; ++i) {
            foo.push_back(i);
            if (sz!=foo.capacity()) {
            sz = foo.capacity();
            std::cout << "capacity changed: " << sz << '\n';
            }
        }

        ft::Vector<int> bar;
        sz = bar.capacity();
        bar.reserve(100);   // this is the only difference with foo above
        std::cout << "making bar grow:\n";
        for (int i=0; i<100; ++i) {
            bar.push_back(i);
            if (sz!=bar.capacity()) {
            sz = bar.capacity();
            std::cout << "capacity changed: " << sz << '\n';
            }
        }
    }


    TITLE_RED("__EMPTY__");
    {
        TITLE_GRN("std");
        std::vector<int> myvector;
        int sum (0);

        for (int i=1;i<=10;i++) myvector.push_back(i);

        while (!myvector.empty())
        {
            sum += myvector.back();
            myvector.pop_back();
        }

        std::cout << "total: " << sum << '\n';
    }
    {
        TITLE_GRN("ft");
        ft::Vector<int> myvector;
        int sum (0);

        for (int i=1;i<=10;i++) myvector.push_back(i);

        while (!myvector.empty())
        {
            sum += myvector.back();
            myvector.pop_back();
        }

        std::cout << "total: " << sum << '\n';
    }


    TITLE_RED("__operator[]__");
    {
        TITLE_GRN("std");
        std::vector<int> myvector (10);   // 10 zero-initialized elements

        std::vector<int>::size_type sz = myvector.size();

        // assign some values:
        for (unsigned i=0; i<sz; i++) myvector[i]=i;

        // reverse vector using operator[]:
        for (unsigned i=0; i<sz/2; i++)
        {
            int temp;
            temp = myvector[sz-1-i];
            myvector[sz-1-i]=myvector[i];
            myvector[i]=temp;
        }

        std::cout << "myvector contains:";
        for (unsigned i=0; i<sz; i++)
            std::cout << ' ' << myvector[i];
        std::cout << '\n';
    }
    {
        TITLE_GRN("ft");
        ft::Vector<int> myvector (10);   // 10 zero-initialized elements

        ft::Vector<int>::size_type sz = myvector.size();

        // assign some values:
        for (unsigned i=0; i<sz; i++) myvector[i]=i;

        // reverse vector using operator[]:
        for (unsigned i=0; i<sz/2; i++)
        {
            int temp;
            temp = myvector[sz-1-i];
            myvector[sz-1-i]=myvector[i];
            myvector[i]=temp;
        }

        std::cout << "myvector contains:";
        for (unsigned i=0; i<sz; i++)
            std::cout << ' ' << myvector[i];
        std::cout << '\n';
    }



    TITLE_RED("__AT__");
    {
        TITLE_GRN("std");
        std::vector<int> myvector (10);   // 10 zero-initialized ints

        // assign some values:
        for (unsigned i=0; i<myvector.size(); i++)
          myvector.at(i)=i;

        std::cout << "myvector contains:";
        for (unsigned i=0; i<myvector.size(); i++)
          std::cout << ' ' << myvector.at(i);
        std::cout << '\n';
    }
    {
        TITLE_GRN("ft");
        ft::Vector<int> myvector (10);   // 10 zero-initialized ints

        // assign some values:
        for (unsigned i=0; i<myvector.size(); i++)
          myvector.at(i)=i;

        std::cout << "myvector contains:";
        for (unsigned i=0; i<myvector.size(); i++)
          std::cout << ' ' << myvector.at(i);
        std::cout << '\n';

    }


    TITLE_RED("__FRONT__");
    {
        TITLE_GRN("std");
        std::vector<int> myvector;

        myvector.push_back(78);
        myvector.push_back(16);

        // now front equals 78, and back 16

        myvector.front() -= myvector.back();

        std::cout << "myvector.front() is now " << myvector.front() << '\n';
    }
    {
        TITLE_GRN("ft");
        ft::Vector<int> myvector;

        myvector.push_back(78);
        myvector.push_back(16);

        // now front equals 78, and back 16

        myvector.front() -= myvector.back();

        std::cout << "myvector.front() is now " << myvector.front() << '\n';
    }


    TITLE_RED("__BACK__");
    {
        TITLE_GRN("std");
        std::vector<int> myvector;

        myvector.push_back(10);

        while (myvector.back() != 0)
        {
            myvector.push_back ( myvector.back() -1 );
        }

        std::cout << "myvector contains:";
        for (unsigned i=0; i<myvector.size() ; i++)
            std::cout << ' ' << myvector[i];
        std::cout << '\n';
    }
    {
        TITLE_GRN("ft");
        ft::Vector<int> myvector;

        myvector.push_back(10);

        while (myvector.back() != 0)
        {
            myvector.push_back ( myvector.back() -1 );
        }

        std::cout << "myvector contains:";
        for (unsigned i=0; i<myvector.size() ; i++)
            std::cout << ' ' << myvector[i];
        std::cout << '\n';
    }

    TITLE_RED("__ASSIGN__");
    {
        TITLE_GRN("std");
        std::vector<int> first;
        std::vector<int> second;
        std::vector<int> third;

        first.assign (7,100);             // 7 ints with a value of 100

        std::vector<int>::iterator it;
        it=first.begin()+1;

        second.assign(it,first.end()-1); // the 5 central values of first

        int myints[] = {1776,7,4};
        third.assign(myints,myints+3);   // assigning from array.

        std::cout << "Size of first: " << int (first.size()) << '\n';
        std::cout << "Size of second: " << int (second.size()) << '\n';
        std::cout << "Size of third: " << int (third.size()) << '\n';
    }
    {
        TITLE_GRN("ft");
        ft::Vector<int> first;
        ft::Vector<int> second;
        ft::Vector<int> third;

        first.assign (7, static_cast<size_t>(100));             // 7 ints with a value of 100

        ft::Vector<int>::iterator it;
        it=first.begin()+1;

        second.assign (it,first.end()-1); // the 5 central values of first

        int myints[] = {1776,7,4};
        third.assign (myints,myints+3);   // assigning from array.

        std::cout << "Size of first: " << int (first.size()) << '\n';
        std::cout << "Size of second: " << int (second.size()) << '\n';
        std::cout << "Size of third: " << int (third.size()) << '\n';
    }


    TITLE_RED("__PUSH/POP_BACK__");
    {
        TITLE_GRN("std");
        std::vector<int> myvector;
        int sum (0);
        myvector.push_back (100);
        myvector.push_back (200);
        myvector.push_back (300);

        while (!myvector.empty())
        {
            sum+=myvector.back();
            myvector.pop_back();
        }

        std::cout << "The elements of myvector add up to " << sum << '\n';
    }
    {
        TITLE_GRN("ft");
        ft::Vector<int> myvector;
        int sum (0);
        myvector.push_back (100);
        myvector.push_back (200);
        myvector.push_back (300);

        while (!myvector.empty())
        {
            sum+=myvector.back();
            myvector.pop_back();
        }

        std::cout << "The elements of myvector add up to " << sum << '\n';
    }

    TITLE_RED("__INSERT__");
    {
        TITLE_GRN("std");
        std::vector<int> myvector (10);   // 10 zero-initialized ints

        // assign some values:
        for (unsigned i=0; i<myvector.size(); i++)
          myvector.at(i)=i;

        std::vector<int>::iterator it;

        it = myvector.begin();
        it = myvector.insert ( it , static_cast<size_t>(200) );

        myvector.insert (it,2,300);

        // "it" no longer valid, get a new one:
        it = myvector.begin();

        std::vector<int> anothervector (2,400);
        myvector.insert (it+2,anothervector.begin(),anothervector.end());

        int myarray [] = { 501,502,503 };
        myvector.insert (myvector.begin(), myarray, myarray+3);

        std::cout << "myvector contains:";
        for (it=myvector.begin(); it<myvector.end(); it++)
            std::cout << ' ' << *it;
        std::cout << '\n';
    }
    {
        TITLE_GRN("ft");
        ft::Vector<int> myvector (10);   // 10 zero-initialized ints

        // assign some values:
        for (unsigned i=0; i<myvector.size(); i++)
          myvector.at(i)=i;

        ft::Vector<int>::iterator it;

        it = myvector.begin();
        it = myvector.insert ( it , 200 );

        myvector.insert (it,static_cast<size_t>(2),300);

        // "it" no longer valid, get a new one:
        it = myvector.begin();

        ft::Vector<int> anothervector (2,static_cast<size_t>(400));
        myvector.insert (it+2,anothervector.begin(),anothervector.end());

        int myarray [] = { 501,502,503 };
        myvector.insert (myvector.begin(), myarray, myarray+3);

        std::cout << "myvector contains:";
        for (it=myvector.begin(); it<myvector.end(); it++)
            std::cout << ' ' << *it;
        std::cout << '\n';
    }

    TITLE_RED("__ERASE__");
    {
        TITLE_GRN("std");
        std::vector<int> myvector;

        // set some values (from 1 to 10)
        for (int i=1; i<=10; i++) myvector.push_back(i);

        // erase the 6th element
        myvector.erase (myvector.begin()+5);

        // erase the first 3 elements:
        myvector.erase (myvector.begin(),myvector.begin()+3);

        std::cout << "myvector contains:";
        for (unsigned i=0; i<myvector.size(); ++i)
            std::cout << ' ' << myvector[i];
        std::cout << '\n';
    }
    {
        TITLE_GRN("ft");
        ft::Vector<int> myvector;

        // set some values (from 1 to 10)
        for (int i=1; i<=10; i++) myvector.push_back(i);

        // erase the 6th element
        myvector.erase (myvector.begin()+5);

        // erase the first 3 elements:
        myvector.erase (myvector.begin(),myvector.begin()+3);

        std::cout << "myvector contains:";
        for (unsigned i=0; i<myvector.size(); ++i)
            std::cout << ' ' << myvector[i];
        std::cout << '\n';
    }


    TITLE_RED("__CLEAR__");
    {
        TITLE_GRN("std");
        std::vector<int> myvector;
        myvector.push_back (100);
        myvector.push_back (200);
        myvector.push_back (300);

        std::cout << "myvector contains:";
        for (unsigned i=0; i<myvector.size(); i++)
            std::cout << ' ' << myvector[i];
        std::cout << '\n';

        myvector.clear();
        myvector.push_back (1101);
        myvector.push_back (2202);

        std::cout << "myvector contains:";
        for (unsigned i=0; i<myvector.size(); i++)
            std::cout << ' ' << myvector[i];
        std::cout << '\n';
    }
    {
        TITLE_GRN("ft");
        ft::Vector<int> myvector;
        myvector.push_back (100);
        myvector.push_back (200);
        myvector.push_back (300);

        std::cout << "myvector contains:";
        for (unsigned i=0; i<myvector.size(); i++)
            std::cout << ' ' << myvector[i];
        std::cout << '\n';

        myvector.clear();
        myvector.push_back (1101);
        myvector.push_back (2202);

        std::cout << "myvector contains:";
        for (unsigned i=0; i<myvector.size(); i++)
            std::cout << ' ' << myvector[i];
        std::cout << '\n';
    }

    TITLE_RED("__SWAP__");
    {
        TITLE_GRN("std");
        std::vector<int> foo (3,100);   // three ints with a value of 100
        std::vector<int> bar (5,200);   // five ints with a value of 200

        foo.swap(bar);

        std::cout << "foo contains:";
        for (unsigned i=0; i<foo.size(); i++)
            std::cout << ' ' << foo[i];
        std::cout << '\n';

        std::cout << "bar contains:";
        for (unsigned i=0; i<bar.size(); i++)
            std::cout << ' ' << bar[i];
        std::cout << '\n';
    }
    {
        TITLE_GRN("ft");
        ft::Vector<int> foo (3, static_cast<size_t>(100));   // three ints with a value of 100
        ft::Vector<int> bar (5, static_cast<size_t>(200));   // five ints with a value of 200

        foo.swap(bar);

        std::cout << "foo contains:";
        for (unsigned i=0; i<foo.size(); i++)
            std::cout << ' ' << foo[i];
        std::cout << '\n';

        std::cout << "bar contains:";
        for (unsigned i=0; i<bar.size(); i++)
            std::cout << ' ' << bar[i];
        std::cout << '\n';
    }


    TITLE_RED("__COMPARISON__");
    {
        TITLE_GRN("std");
        std::vector<int> foo (3,100);   // three ints with a value of 100
        std::vector<int> bar (2,200);   // two ints with a value of 200

        if (foo==bar) std::cout << "foo and bar are equal\n";
        if (foo!=bar) std::cout << "foo and bar are not equal\n";
        if (foo< bar) std::cout << "foo is less than bar\n";
        if (foo> bar) std::cout << "foo is greater than bar\n";
        if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
        if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
    }
    {
        TITLE_GRN("ft");
        ft::Vector<int> foo (static_cast<size_t>(3),100);   // three ints with a value of 100
        ft::Vector<int> bar (static_cast<size_t>(2),200);   // two ints with a value of 200

        if (foo==bar) std::cout << "foo and bar are equal\n";
        if (foo!=bar) std::cout << "foo and bar are not equal\n";
        if (foo< bar) std::cout << "foo is less than bar\n";
        if (foo> bar) std::cout << "foo is greater than bar\n";
        if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
        if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
    }

    TITLE_RED("__N-M_SWAP__");
    {
        TITLE_GRN("std");
        std::vector<int> foo (3,100);   // three ints with a value of 100
        std::vector<int> bar (5,200);   // five ints with a value of 200

        swap(foo,bar);

        std::cout << "foo contains:";
        for (std::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';

        std::cout << "bar contains:";
        for (std::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
    }
    {
        TITLE_GRN("ft");
        ft::Vector<int> foo (static_cast<size_t>(3),100);   // three ints with a value of 100
        ft::Vector<int> bar (static_cast<size_t>(5),200);   // five ints with a value of 200

        swap(foo,bar);

        std::cout << "foo contains:";
        for (ft::Vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';

        std::cout << "bar contains:";
        for (ft::Vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
    }
}