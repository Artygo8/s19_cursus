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
#include <map>
#include <vector>
#include <math.h>
#include <iostream>
#include "alloc.hpp"
#include "map.hpp"

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

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

//                  _       
//                 (_)      
//  _ __ ___   __ _ _ _ __  
// | '_ ` _ \ / _` | | '_ | 
// | | | | | | (_| | | | | |
// |_| |_| |_|\__,_|_|_| |_|
//                          

int main()
{
    TITLE_RED("__MAP_CONSTRUCTORS__");
    {
        TITLE_GRN("std");
        std::map<char,int> first;

        first['a']=10;
        first['b']=30;
        first['c']=50;
        first['d']=70;

        std::map<char,int> second (first.begin(),first.end());

        std::map<char,int> third (second);

        std::map<char,int,classcomp> fourth;                 // class as Compare

        bool(*fn_pt)(char,char) = fncomp;
        std::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
    }
    {
        TITLE_GRN("ft");
        ft::map<char,int> first;

        first['a']=10;
        first['b']=30;
        first['c']=50;
        first['d']=70;

        ft::map<char,int> second (first.begin(),first.end());

        ft::map<char,int> third (second);

        ft::map<char,int,classcomp> fourth;                 // class as Compare

        bool(*fn_pt)(char,char) = fncomp;
        ft::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
    }

return 0;

    TITLE_RED("____");
    {
        TITLE_GRN("std");
        std::map<char,int> mymap;

        mymap['b'] = 100;
        mymap['a'] = 200;
        mymap['c'] = 300;

        // show content:
        for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
    {
        TITLE_GRN("ft");
        ft::map<char,int> mymap;

        mymap['b'] = 100;
        mymap['a'] = 200;
        mymap['c'] = 300;

        // show content:
        for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
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