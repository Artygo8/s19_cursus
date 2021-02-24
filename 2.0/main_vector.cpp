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
#include "vector.hpp"

#ifndef MY_COLORS
# define MY_COLORS
# define R_CYN "\e[46;30m"
# define R_MGN "\e[45;30m"
# define R_BLU "\e[44;30m"
# define R_YLW "\e[43;30m"
# define R_GRN "\e[42;30m"
# define R_RED "\e[41;30m"
# define CYN "\e[36m"
# define MGN "\e[35m"
# define BLU "\e[34m"
# define YLW "\e[33m"
# define GRN "\e[32m"
# define RED "\e[31m"
# define NC "\e[m"
#endif

using std::string;
using std::cout;
using std::endl;

template< typename T >
void TITLE_RED(T str) {std::cout << R_RED << str << NC << std::endl;}
template< typename T >
void TITLE_BLU(T str) {std::cout << R_BLU << str << NC << std::endl;}
template< typename T >
void TITLE_GRN(T str) {std::cout << R_GRN << str << NC << std::endl;}

//  _              _     
// | |            | |    
// | |_ ___   ___ | |___ 
// | __/ _ \ / _ \| / __|
// | || (_) | (_) | \__ \\
//  \__\___/ \___/|_|___/
//                       

// a predicate implemented as a function:
bool single_digit (const int& value) { return (value<10); }

// a predicate implemented as a class:
struct is_odd {
  bool operator() (const int& value) { return (value%2)==1; }
};

// a binary predicate implemented as a function:
bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

// a binary predicate implemented as a class:
struct is_near {
  bool operator() (double first, double second)
  { return (fabs(first-second)<5.0); }
};

// compare only integral part:
bool mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }

// comparison, not case sensitive.
bool compare_nocase (const std::string& first, const std::string& second)
{
  unsigned int i=0;
  while ( (i<first.length()) && (i<second.length()) )
  {
    if (tolower(first[i])<tolower(second[i])) return true;
    else if (tolower(first[i])>tolower(second[i])) return false;
    ++i;
  }
  return ( first.length() < second.length() );
}

//                  _       
//                 (_)      
//  _ __ ___   __ _ _ _ __  
// | '_ ` _ \ / _` | | '_ | 
// | | | | | | (_| | | | | |
// |_| |_| |_|\__,_|_|_| |_|
//                          

int main()
{
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
        ft::vector<int> first;                                // empty vector of ints
        ft::vector<int> second (static_cast<size_t>(4),100);                       // four ints with value 100
        ft::vector<int> third (second.begin(),second.end());  // iterating through second
        ft::vector<int> fourth (third);                       // a copy of third
        
        // the iterator constructor can also be used to construct from arrays:
        int myints[] = {16,2,77,29};
        ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
        
        std::cout << "The contents of fifth are:";
        for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
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
        ft::vector<int> foo (static_cast<size_t>(3),0);
        ft::vector<int> bar (static_cast<size_t>(5),0);

        bar = foo;
        foo = ft::vector<int>();

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
        ft::vector<int> myvector;
        for (int i=1; i<=5; i++) myvector.push_back(i);

        std::cout << "myvector contains:";
        for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
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
        ft::vector<int> myvector (5);  // 5 default-constructed ints

        int i=0;

        ft::vector<int>::reverse_iterator rit = myvector.rbegin();
        for (; rit!= myvector.rend(); ++rit)
            * rit = ++i;

        std::cout << "myvector contains:";
        for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
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
        ft::vector<int> myints;
        std::cout << "0. size: " << myints.size() << '\n';
        
        for (int i=0; i<10; i++) myints.push_back(i);
        std::cout << "1. size: " << myints.size() << '\n';
        
        myints.insert (myints.end(),10,100);
        std::cout << "2. size: " << myints.size() << '\n';
        
        myints.pop_back();
        std::cout << "3. size: " << myints.size() << '\n';
    }

    return 0;

    TITLE_RED("____");
    {
        TITLE_GRN("std");
    }
    {
        TITLE_GRN("ft");
    }

    TITLE_RED("____");
    {
        TITLE_GRN("std");
    }
    {
        TITLE_GRN("ft");
    }

    TITLE_RED("____");
    {
        TITLE_GRN("std");
    }
    {
        TITLE_GRN("ft");
    }

    TITLE_RED("____");
    {
        TITLE_GRN("std");
    }
    {
        TITLE_GRN("ft");
    }

    TITLE_RED("____");
    {
        TITLE_GRN("std");
    }
    {
        TITLE_GRN("ft");
    }

    TITLE_RED("____");
    {
        TITLE_GRN("std");
    }
    {
        TITLE_GRN("ft");
    }

    TITLE_RED("____");
    {
        TITLE_GRN("std");
    }
    {
        TITLE_GRN("ft");
    }

    TITLE_RED("____");
    {
        TITLE_GRN("std");
    }
    {
        TITLE_GRN("ft");
    }

    TITLE_RED("____");
    {
        TITLE_GRN("std");
    }
    {
        TITLE_GRN("ft");
    }

    TITLE_RED("____");
    {
        TITLE_GRN("std");
    }
    {
        TITLE_GRN("ft");
    }

    TITLE_RED("____");
    {
        TITLE_GRN("std");
    }
    {
        TITLE_GRN("ft");
    }

    TITLE_RED("____");
    {
        TITLE_GRN("std");
    }
    {
        TITLE_GRN("ft");
    }

    TITLE_RED("____");
    {
        TITLE_GRN("std");
    }
    {
        TITLE_GRN("ft");
    }

    TITLE_RED("____");
    {
        TITLE_GRN("std");
    }
    {
        TITLE_GRN("ft");
    }

    TITLE_RED("____");
    {
        TITLE_GRN("std");
    }
    {
        TITLE_GRN("ft");
    }

    TITLE_RED("____");
    {
        TITLE_GRN("std");
    }
    {
        TITLE_GRN("ft");
    }

    TITLE_RED("____");
    {
        TITLE_GRN("std");
    }
    {
        TITLE_GRN("ft");
    }

    TITLE_RED("____");
    {
        TITLE_GRN("std");
    }
    {
        TITLE_GRN("ft");
    }

    TITLE_RED("____");
    {
        TITLE_GRN("std");
    }
    {
        TITLE_GRN("ft");
    }

    TITLE_RED("____");
    {
        TITLE_GRN("std");
    }
    {
        TITLE_GRN("ft");
    }

    TITLE_RED("____");
    {
        TITLE_GRN("std");
    }
    {
        TITLE_GRN("ft");
    }

    TITLE_RED("____");
    {
        TITLE_GRN("std");
    }
    {
        TITLE_GRN("ft");
    }

    TITLE_RED("____");
    {
        TITLE_GRN("std");
    }
    {
        TITLE_GRN("ft");
    }

    TITLE_RED("____");
    {
        TITLE_GRN("std");
    }
    {
        TITLE_GRN("ft");
    }

    TITLE_RED("____");
    {
        TITLE_GRN("std");
    }
    {
        TITLE_GRN("ft");
    }

    TITLE_RED("____");
    {
        TITLE_GRN("std");
    }
    {
        TITLE_GRN("ft");
    }

    TITLE_RED("____");
    {
        TITLE_GRN("std");
    }
    {
        TITLE_GRN("ft");
    }

    TITLE_RED("____");
    {
        TITLE_GRN("std");
    }
    {
        TITLE_GRN("ft");
    }

    TITLE_RED("____");
    {
        TITLE_GRN("std");
    }
    {
        TITLE_GRN("ft");
    }

    TITLE_RED("____");
    {
        TITLE_GRN("std");
    }
    {
        TITLE_GRN("ft");
    }

    TITLE_RED("____");
    {
        TITLE_GRN("std");
    }
    {
        TITLE_GRN("ft");
    }

    TITLE_RED("____");
    {
        TITLE_GRN("std");
    }
    {
        TITLE_GRN("ft");
    }

    TITLE_RED("____");
    {
        TITLE_GRN("std");
    }
    {
        TITLE_GRN("ft");
    }

    TITLE_RED("____");
    {
        TITLE_GRN("std");
    }
    {
        TITLE_GRN("ft");
    }

    TITLE_RED("____");
    {
        TITLE_GRN("std");
    }
    {
        TITLE_GRN("ft");
    }

    TITLE_RED("____");
    {
        TITLE_GRN("std");
    }
    {
        TITLE_GRN("ft");
    }

    TITLE_RED("____");
    {
        TITLE_GRN("std");
    }
    {
        TITLE_GRN("ft");
    }

    TITLE_RED("____");
    {
        TITLE_GRN("std");
    }
    {
        TITLE_GRN("ft");
    }

    TITLE_RED("____");
    {
        TITLE_GRN("std");
    }
    {
        TITLE_GRN("ft");
    }

    TITLE_RED("____");
    {
        TITLE_GRN("std");
    }
    {
        TITLE_GRN("ft");
    }

    return 0;
}