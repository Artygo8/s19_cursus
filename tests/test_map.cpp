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
#include "test.hpp"
#include "../ft_containers/map.hpp"


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

void test_map()
{

    TITLE_MGN("                        ");
    TITLE_MGN("  _ __ ___   __ _ _ __  ");
    TITLE_MGN(" | '_ ` _ \\ / _` | '_ \\ ");
    TITLE_MGN(" | | | | | | (_| | |_) |");
    TITLE_MGN(" |_| |_| |_|\\__,_| .__/ ");
    TITLE_MGN("                 |_|    ");

    TITLE_RED("__MAP_CONSTRUCTORS__");
    {
        TITLE_GRN("std");
        std::map<char,int> first;

        first['a']=10;
        first['b']=30;
        first['c']=50;
        first['d']=70;

        for (std::map<char,int>::iterator it = first.begin(); it != first.end(); ++it)
            std::cout << (*it).first << "=" << (*it).second << std::endl;

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

        for (ft::map<char,int>::iterator it = first.begin(); it != first.end(); ++it)
            std::cout << (*it).first << "=" << (*it).second << std::endl;

        ft::map<char,int> second (first.begin(),first.end());

        ft::map<char,int> third (second);

        ft::map<char,int,classcomp> fourth;                 // class as Compare

        bool(*fn_pt)(char,char) = fncomp;
        ft::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
    }

    TITLE_RED("__ASSIGNMENT__");
    {
        TITLE_GRN("std");
        std::map<char,int> first;
        std::map<char,int> second;

        first['x']=8;
        first['y']=16;
        first['z']=32;

        second=first;                // second now contains 3 ints
        first=std::map<char,int>();  // and first is now empty

        std::cout << "Size of first: " << first.size() << '\n';
        std::cout << "Size of second: " << second.size() << '\n';
    }
    {
        TITLE_GRN("ft");
        ft::map<char,int> first;
        ft::map<char,int> second;

        first['x']=8;
        first['y']=16;
        first['z']=32;

        second=first;                // second now contains 3 ints
        first=ft::map<char,int>();  // and first is now empty

        std::cout << "Size of first: " << first.size() << '\n';
        std::cout << "Size of second: " << second.size() << '\n';
    }

    TITLE_RED("__BEGIN/END__");
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

    TITLE_RED("__RBEGIN/REND__");
    {
        TITLE_GRN("std");
        std::map<char,int> mymap;

        mymap['x'] = 100;
        mymap['y'] = 200;
        mymap['z'] = 300;

        // show content:
        std::map<char,int>::reverse_iterator rit;
        for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
            std::cout << rit->first << " => " << rit->second << '\n';
    }
    {
        TITLE_GRN("ft");
        ft::map<char,int> mymap;

        mymap['x'] = 100;
        mymap['y'] = 200;
        mymap['z'] = 300;

        // show content:
        ft::map<char,int>::reverse_iterator rit;
        for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
            std::cout << rit->first << " => " << rit->second << '\n';
    }

    TITLE_RED("__EMPTY__");
    {
        TITLE_GRN("std");
        std::map<char,int> mymap;

        mymap['a']=10;
        mymap['b']=20;
        mymap['c']=30;

        while (!mymap.empty())
        {
            std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
            mymap.erase(mymap.begin());
        }
    }
    {
        TITLE_GRN("ft");
        ft::map<char,int> mymap;

        mymap['a']=10;
        mymap['b']=20;
        mymap['c']=30;

        while (!mymap.empty())
        {
            std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
            mymap.erase(mymap.begin());
        }
    }

    TITLE_RED("__SIZE__");
    {
        TITLE_GRN("std");
        std::map<char,int> mymap;
        mymap['a']=101;
        mymap['b']=202;
        mymap['c']=302;

        std::cout << "mymap.size() is " << mymap.size() << '\n';
    }
    {
        TITLE_GRN("ft");
        ft::map<char,int> mymap;
        mymap['a']=101;
        mymap['b']=202;
        mymap['c']=302;

        std::cout << "mymap.size() is " << mymap.size() << '\n';
    }

    TITLE_RED("__MAX_SIZE__");
    {
        TITLE_GRN("std");
        int i;
        std::map<int,int> mymap;

        if (mymap.max_size()>1000)
        {
            for (i=0; i<1000; i++) mymap[i]=0;
            std::cout << "The map contains 1000 elements.\n";
        }
        else std::cout << "The map could not hold 1000 elements.\n";
    }
    {
        TITLE_GRN("ft");
        int i;
        ft::map<int,int> mymap;

        if (mymap.max_size()>1000)
        {
            for (i=0; i<1000; i++) mymap[i]=0;
            std::cout << "The map contains 1000 elements.\n";
        }
        else std::cout << "The map could not hold 1000 elements.\n";
    }

    TITLE_RED("__INSERT__");
    {
        TITLE_GRN("std");
        std::map<char,int> mymap;

        // first insert function version (single parameter):
        mymap.insert ( std::pair<const char,int>('a',100) );
        mymap.insert ( std::pair<const char,int>('z',200) );

        std::pair<std::map<char,int>::iterator,bool> ret;
        ret = mymap.insert ( std::pair<const char,int>('z',500) );
        if (ret.second==false) {
            std::cout << "element 'z' already existed";
            std::cout << " with a value of " << ret.first->second << '\n';
        }

        // second insert function version (with hint position):
        std::map<char,int>::iterator it = mymap.begin();
        mymap.insert (it, std::pair<const char,int>('b',300));  // max efficiency inserting
        mymap.insert (it, std::pair<const char,int>('c',400));  // no max efficiency inserting

        // third insert function version (range insertion):
        std::map<char,int> anothermap;
        anothermap.insert(mymap.begin(),mymap.find('c'));

        // showing contents:
        std::cout << "mymap contains:\n";
        for (it=mymap.begin(); it!=mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';

        std::cout << "anothermap contains:\n";
        for (it=anothermap.begin(); it!=anothermap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
    {
        TITLE_GRN("ft");
        ft::map<char,int> mymap;

        // first insert function version (single parameter):
        mymap.insert ( ft::pair<const char,int>('a',100) );
        mymap.insert ( ft::pair<const char,int>('z',200) );

        ft::pair<ft::map<char,int>::iterator,bool> ret;
        ret = mymap.insert ( ft::pair<const char,int>('z',500) );
        if (ret.second==false) {
            std::cout << "element 'z' already existed";
            std::cout << " with a value of " << ret.first->second << '\n';
        }

        // second insert function version (with hint position):
        ft::map<char,int>::iterator it = mymap.begin();
        mymap.insert (it, ft::pair<const char,int>('b',300));  // max efficiency inserting
        mymap.insert (it, ft::pair<const char,int>('c',400));  // no max efficiency inserting

        // third insert function version (range insertion):
        ft::map<char,int> anothermap;
        anothermap.insert(mymap.begin(),mymap.find('c'));

        // showing contents:
        std::cout << "mymap contains:\n";
        for (it=mymap.begin(); it!=mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';

        std::cout << "anothermap contains:\n";
        for (it=anothermap.begin(); it!=anothermap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }

    TITLE_RED("__OPERATOR[]__");
    {
        TITLE_GRN("std");
        std::map<char,std::string> mymap;

        mymap['a']="an element";
        mymap['b']="another element";
        mymap['c']=mymap['b'];

        std::cout << "mymap['a'] is " << mymap['a'] << '\n';
        std::cout << "mymap['b'] is " << mymap['b'] << '\n';
        std::cout << "mymap['c'] is " << mymap['c'] << '\n';
        std::cout << "mymap['d'] is " << mymap['d'] << '\n';

        std::cout << "mymap now contains " << mymap.size() << " elements.\n";
    }
    {
        TITLE_GRN("ft");
        ft::map<char,std::string> mymap;

        mymap['a']="an element";
        mymap['b']="another element";
        mymap['c']=mymap['b'];

        std::cout << "mymap['a'] is " << mymap['a'] << '\n';
        std::cout << "mymap['b'] is " << mymap['b'] << '\n';
        std::cout << "mymap['c'] is " << mymap['c'] << '\n';
        std::cout << "mymap['d'] is " << mymap['d'] << '\n';

        std::cout << "mymap now contains " << mymap.size() << " elements.\n";
    }



    TITLE_RED("__SWAP__");
    {
        TITLE_GRN("std");
        std::map<char,int> foo,bar;

        foo['x']=100;
        foo['y']=200;

        bar['a']=11;
        bar['b']=22;
        bar['c']=33;

        foo.swap(bar);

        std::cout << "foo contains:\n";
        for (std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';

        std::cout << "bar contains:\n";
        for (std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
    {
        TITLE_GRN("ft");
        ft::map<char,int> foo,bar;

        foo['x']=100;
        foo['y']=200;

        bar['a']=11;
        bar['b']=22;
        bar['c']=33;

        foo.swap(bar);

        std::cout << "foo contains:\n";
        for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';

        std::cout << "bar contains:\n";
        for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }

    TITLE_RED("__CLEAR__");
    {
        TITLE_GRN("std");
        std::map<char,int> mymap;

        mymap['x']=100;
        mymap['y']=200;
        mymap['z']=300;

        std::cout << "mymap contains:\n";
        for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';

        mymap.clear();
        mymap['a']=1101;
        mymap['b']=2202;

        std::cout << "mymap contains:\n";
        for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
    {
        TITLE_GRN("ft");
        ft::map<char,int> mymap;

        mymap['x']=100;
        mymap['y']=200;
        mymap['z']=300;

        std::cout << "mymap contains:\n";
        for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';

        mymap.clear();
        mymap['a']=1101;
        mymap['b']=2202;

        std::cout << "mymap contains:\n";
        for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }

    TITLE_RED("__KEY_COMP__");
    {
        TITLE_GRN("std");
        std::map<char,int> mymap;

        std::map<char,int>::key_compare mycomp = mymap.key_comp();

        mymap['a']=100;
        mymap['b']=200;
        mymap['c']=300;

        std::cout << "mymap contains:\n";

        char highest = mymap.rbegin()->first;     // key value of last element

        std::map<char,int>::iterator it = mymap.begin();
        do {
            std::cout << it->first << " => " << it->second << '\n';
        } while ( mycomp((*it++).first, highest) );

        std::cout << '\n';
    }
    {
        TITLE_GRN("ft");
        ft::map<char,int> mymap;

        ft::map<char,int>::key_compare mycomp = mymap.key_comp();

        mymap['a']=100;
        mymap['b']=200;
        mymap['c']=300;

        std::cout << "mymap contains:\n";

        char highest = mymap.rbegin()->first;     // key value of last element

        ft::map<char,int>::iterator it = mymap.begin();
        do {
            std::cout << it->first << " => " << it->second << '\n';
        } while ( mycomp((*it++).first, highest) );

        std::cout << '\n';
    }

    TITLE_RED("__VALUE_COMPARE__");
    {
        TITLE_GRN("std");
        std::map<char,int> mymap;

        mymap['x']=1001;
        mymap['y']=2002;
        mymap['z']=3003;

        std::cout << "mymap contains:\n";

        std::pair<char,int> highest = *mymap.rbegin();          // last element

        std::map<char,int>::iterator it = mymap.begin();
        do {
            std::cout << it->first << " => " << it->second << '\n';
        } while ( mymap.value_comp()(*it++, highest) );
    }
    {
        TITLE_GRN("ft");
        ft::map<char,int> mymap;

        mymap['x']=1001;
        mymap['y']=2002;
        mymap['z']=3003;

        std::cout << "mymap contains:\n";

        ft::pair<const char,int> highest = *mymap.rbegin();          // last element

        ft::map<char,int>::iterator it = mymap.begin();
        do {
            std::cout << it->first << " => " << it->second << '\n';
        } while ( mymap.value_comp()(*it++, highest) );
    }

    TITLE_RED("__FIND__");
    {
        TITLE_GRN("std");
        std::map<char,int> mymap;
        std::map<char,int>::iterator it;

        mymap['a']=50;
        mymap['b']=100;
        mymap['c']=150;
        mymap['d']=200;

        it = mymap.find('b');
        if (it != mymap.end())
            mymap.erase (it);

        // print content:
        std::cout << "elements in mymap:" << '\n';
        std::cout << "a => " << mymap.find('a')->second << '\n';
        std::cout << "c => " << mymap.find('c')->second << '\n';
        std::cout << "d => " << mymap.find('d')->second << '\n';
    }
    {
        TITLE_GRN("ft");
        ft::map<char,int> mymap;
        ft::map<char,int>::iterator it;

        mymap['a']=50;
        mymap['b']=100;
        mymap['c']=150;
        mymap['d']=200;

        it = mymap.find('b');
        if (it != mymap.end())
            mymap.erase (it);

        // print content:
        std::cout << "elements in mymap:" << '\n';
        std::cout << "a => " << mymap.find('a')->second << '\n';
        std::cout << "c => " << mymap.find('c')->second << '\n';
        std::cout << "d => " << mymap.find('d')->second << '\n';
    }

    TITLE_RED("__COUNT__");
    {
        TITLE_GRN("std");
        std::map<char,int> mymap;
        char c;

        mymap ['a']=101;
        mymap ['c']=202;
        mymap ['f']=303;

        for (c='a'; c<'h'; c++)
        {
            std::cout << c;
            if (mymap.count(c)>0)
            std::cout << " is an element of mymap.\n";
            else 
            std::cout << " is not an element of mymap.\n";
        }
    }
    {
        TITLE_GRN("ft");
        ft::map<char,int> mymap;
        char c;

        mymap ['a']=101;
        mymap ['c']=202;
        mymap ['f']=303;

        for (c='a'; c<'h'; c++)
        {
            std::cout << c;
            if (mymap.count(c)>0)
            std::cout << " is an element of mymap.\n";
            else 
            std::cout << " is not an element of mymap.\n";
        }
    }

    TITLE_RED("__LOWER/UPPER_BOUND__");
    {
        TITLE_GRN("std");
        std::map<char,int> mymap;
        std::map<char,int>::iterator itlow,itup;

        mymap['a']=20;
        mymap['b']=40;
        mymap['c']=60;
        mymap['d']=80;
        mymap['e']=100;

        itlow=mymap.lower_bound ('b');  // itlow points to b
        itup=mymap.upper_bound ('d');   // itup points to e (not d!)

        mymap.erase(itlow,itup);        // erases [itlow,itup)

        // print content:
        for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
    {
        TITLE_GRN("ft");
        ft::map<char,int> mymap;
        ft::map<char,int>::iterator itlow,itup;

        mymap['a']=20;
        mymap['b']=40;
        mymap['c']=60;
        mymap['d']=80;
        mymap['e']=100;

        itlow=mymap.lower_bound ('b');  // itlow points to b
        itup=mymap.upper_bound ('d');   // itup points to e (not d!)

        mymap.erase(itlow,itup);        // erases [itlow,itup)

        // print content:
        for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }

    TITLE_RED("__EQUAL_RANGE__");
    {
        TITLE_GRN("std");
        std::map<char,int> mymap;

        mymap['a']=10;
        mymap['b']=20;
        mymap['c']=30;

        std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
        ret = mymap.equal_range('b');

        std::cout << "lower bound points to: ";
        std::cout << ret.first->first << " => " << ret.first->second << '\n';

        std::cout << "upper bound points to: ";
        std::cout << ret.second->first << " => " << ret.second->second << '\n';
    }
    {
        TITLE_GRN("ft");
        ft::map<char,int> mymap;

        mymap['a']=10;
        mymap['b']=20;
        mymap['c']=30;

        ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
        ret = mymap.equal_range('b');

        std::cout << "lower bound points to: ";
        std::cout << ret.first->first << " => " << ret.first->second << '\n';

        std::cout << "upper bound points to: ";
        std::cout << ret.second->first << " => " << ret.second->second << '\n';
    }
    return ;
}