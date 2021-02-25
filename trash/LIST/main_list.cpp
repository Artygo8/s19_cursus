/* ************************************************************************** */
/*																																						*/
/*																												:::			::::::::	 */
/*	 main.cpp																					 :+:			:+:		:+:	 */
/*																										+:+ +:+				 +:+		 */
/*	 By: agossuin <agossuin@student.s19.be>				 +#+	+:+			 +#+				*/
/*																								+#+#+#+#+#+	 +#+					 */
/*	 Created: 2020/12/28 12:00:01 by agossuin					#+#		#+#						 */
/*	 Updated: 2020/12/28 12:00:01 by agossuin				 ###	 ########.fr			 */
/*																																						*/
/* ************************************************************************** */

#include <vector>
#include "list.hpp"

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
	TITLE_RED("__LIST_CONSTRUCTORS__");
	{
		TITLE_GRN("std");
		// constructors used in the same order as described above:
		std::list<int> first;																// empty list of ints
		std::list<int> second (4,100);											 // four ints with value 100
		std::list<int> third (second.begin(),second.end());	// iterating through second
		std::list<int> fourth (third);											 // a copy of third

		// the iterator constructor can also be used to construct from arrays:
		int myints[] = {16,2,77,29};
		std::list<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

		std::cout << "The contents of fifth are: ";
		for (std::list<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
			std::cout << *it << ' ';
		std::cout << '\n';
	}
	{
		TITLE_GRN("ft");
		// constructors used in the same order as described above:
		ft::list<int> first;																// empty list of ints
		ft::list<int> second (4, 100);											// four ints with value 100
		ft::list<int> third (second.begin(),second.end());	// iterating through second
		ft::list<int> fourth (third);											 // a copy of third

		// the iterator constructor can also be used to construct from arrays:
		int myints[] = {16,2,77,29};
		ft::list<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

		std::cout << "The contents of fifth are: ";
		for (ft::list<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
			std::cout << *it << ' ';
		std::cout << '\n';
	}

	TITLE_RED("__LIST_ASSIGNEMENT__");
	{
		TITLE_GRN("std");
		std::list<int> first (3);			// list of 3 zero-initialized ints
		std::list<int> second (5);		 // list of 5 zero-initialized ints

		second = first;
		first = std::list<int>();

		std::cout << "Size of first: " << int (first.size()) << '\n';
		std::cout << "Size of second: " << int (second.size()) << '\n';
	}
	{
		TITLE_GRN("ft");
		ft::list<int> first (3);			// list of 3 zero-initialized ints
		ft::list<int> second (5);		 // list of 5 zero-initialized ints

		second = first;
		first = ft::list<int>();

		std::cout << "Size of first: " << int (first.size()) << '\n';
		std::cout << "Size of second: " << int (second.size()) << '\n';
	}

	TITLE_RED("__BEGIN_ITERATOR__");
	{
		TITLE_GRN("std");
		int myints[] = {75,23,65,42,13};
		std::list<int> mylist (myints,myints+5);

		std::cout << "mylist contains:";
		for (std::list<int>::iterator it=mylist.begin(); it != mylist.end(); ++it)
			std::cout << ' ' << *it;

		std::cout << '\n';
	}
	{
		TITLE_GRN("ft");
		int myints[] = {75,23,65,42,13};
		ft::list<int> mylist (myints,myints+5);

		std::cout << "mylist contains:";
		for (ft::list<int>::iterator it=mylist.begin(); it != mylist.end(); ++it)
			std::cout << ' ' << *it;

		std::cout << '\n';
	}

	TITLE_RED("__RBEGIN_ITERATOR__");
	{
		TITLE_GRN("std");
		std::list<int> mylist;
		for (int i=1; i<=5; ++i) mylist.push_back(i);

		std::cout << "mylist backwards:";
		for (std::list<int>::reverse_iterator rit=mylist.rbegin(); rit!=mylist.rend(); ++rit)
			std::cout << ' ' << *rit;
		std::cout << '\n';
	}
	{
		TITLE_GRN("ft");
		ft::list<int> mylist;
		for (int i=1; i<=5; ++i) mylist.push_back(i);

		std::cout << "mylist backwards:";
		for (ft::list<int>::reverse_iterator rit=mylist.rbegin(); rit!=mylist.rend(); ++rit)
			std::cout << ' ' << *rit;
		std::cout << '\n';
	}


	TITLE_RED("__EMPTY__");
	{
		TITLE_GRN("std");
		std::list<int> mylist;
		int sum (0);

		for (int i=1;i<=10;++i) mylist.push_back(i);

		while (!mylist.empty())
		{
			sum += mylist.front();
			mylist.pop_front();
		}

		std::cout << "total: " << sum << '\n';
	}
	{
		TITLE_GRN("ft");
		ft::list<int> mylist;
		int sum (0);

		for (int i=1;i<=10;++i) mylist.push_back(i);

		while (!mylist.empty())
		{
			sum += mylist.front();
			mylist.pop_front();
		}

		std::cout << "total: " << sum << '\n';
	}

	TITLE_RED("__SIZE__");
	{
		TITLE_GRN("std");
		std::list<int> myints;
		std::cout << "0. size: " << myints.size() << '\n';

		for (int i=0; i<10; i++) myints.push_back(i);
			std::cout << "1. size: " << myints.size() << '\n';

		myints.insert (myints.begin(),10,100);
		std::cout << "2. size: " << myints.size() << '\n';

		myints.pop_back();
		std::cout << "3. size: " << myints.size() << '\n';
	}
	{
		TITLE_GRN("ft");
		ft::list<int> myints;
		std::cout << "0. size: " << myints.size() << '\n';

		for (int i=0; i<10; i++) myints.push_back(i);
			std::cout << "1. size: " << myints.size() << '\n';

		myints.insert (myints.begin(),10,100);
		std::cout << "2. size: " << myints.size() << '\n';

		myints.pop_back();
		std::cout << "3. size: " << myints.size() << '\n';
	}

	TITLE_RED("__MAX_SIZE__");
	{
		TITLE_GRN("std");
		std::list<int> mylist;

		std::cout << "max_size : " << mylist.max_size() << std::endl;
	}
	{
		TITLE_GRN("ft");
		ft::list<int> mylist;

		std::cout << "max_size : " << mylist.max_size() << std::endl;
	}

	TITLE_RED("__FRONT__");
	{
		TITLE_GRN("std");
		std::list<int> mylist;

		mylist.push_back(77);
		mylist.push_back(22);

		// now front equals 77, and back 22

		mylist.front() -= mylist.back();

		std::cout << "mylist.front() is now " << mylist.front() << '\n';
	}
	{
		TITLE_GRN("ft");
		ft::list<int> mylist;
	
		mylist.push_back(77);
		mylist.push_back(22);
	
		// now front equals 77, and back 22
	
		mylist.front() -= mylist.back();
	
		std::cout << "mylist.front() is now " << mylist.front() << '\n';
	}

	TITLE_RED("__BACK__");
	{
		TITLE_GRN("std");
		std::list<int> mylist;

		mylist.push_back(10);

		while (mylist.back() != 0)
		{
			mylist.push_back ( mylist.back() -1 );
		}

		std::cout << "mylist contains:";
		for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end() ; ++it)
			std::cout << ' ' << *it;

		std::cout << '\n';
	}
	{
		TITLE_GRN("ft");
		ft::list<int> mylist;
	
		mylist.push_back(10);
	
		while (mylist.back() != 0)
		{
			mylist.push_back ( mylist.back() -1 );
		}
	
		std::cout << "mylist contains:";
		for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end() ; ++it)
			std::cout << ' ' << *it;
	
		std::cout << '\n';
	}

	TITLE_RED("__ASSIGN__");
	{
		TITLE_GRN("std");
		std::list<int> first;
		std::list<int> second;

		first.assign (7,100);											// 7 ints with value 100

		second.assign (first.begin(),first.end()); // a copy of first

		int myints[]={1776,7,4};
		first.assign (myints,myints+3);						// assigning from array

		std::cout << "Size of first: " << int (first.size()) << '\n';
		std::cout << "Size of second: " << int (second.size()) << '\n';
	}
	{
		TITLE_GRN("ft");
		ft::list<int> first;
		ft::list<int> second;
	
		first.assign (7,100);											// 7 ints with value 100
	
		second.assign (first.begin(),first.end()); // a copy of first
	
		int myints[]={1776,7,4};
		first.assign (myints,myints+3);						// assigning from array
	
		std::cout << "Size of first: " << int (first.size()) << '\n';
		std::cout << "Size of second: " << int (second.size()) << '\n';
	}

	TITLE_RED("__PUSH_FRONT__");
	{
		TITLE_GRN("std");
		std::list<int> mylist (2,100);				 // two ints with a value of 100
		mylist.push_front (200);
		mylist.push_front (300);

		std::cout << "mylist contains:";
		for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;

		std::cout << '\n';
	}
	{
		TITLE_GRN("ft");
		ft::list<int> mylist (2,100);				 // two ints with a value of 100
		mylist.push_front (200);
		mylist.push_front (300);

		std::cout << "mylist contains:";
		for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;

		std::cout << '\n';
	}

	TITLE_RED("__POP_FRONT__");
	{
		TITLE_GRN("std");
		std::list<int> mylist;
		mylist.push_back (100);
		mylist.push_back (200);
		mylist.push_back (300);

		std::cout << "Popping out the elements in mylist:";
		while (!mylist.empty())
		{
			std::cout << ' ' << mylist.front();
			mylist.pop_front();
		}

		std::cout << "\nFinal size of mylist is " << mylist.size() << '\n';
	}
	{
		TITLE_GRN("ft");
		ft::list<int> mylist;
		mylist.push_back (100);
		mylist.push_back (200);
		mylist.push_back (300);

		std::cout << "Popping out the elements in mylist:";
		while (!mylist.empty())
		{
			std::cout << ' ' << mylist.front();
			mylist.pop_front();
		}

		std::cout << "\nFinal size of mylist is " << mylist.size() << '\n';
	}

	TITLE_RED("__PUSH_BACK__");
	{
		TITLE_GRN("std");
		std::list<int> mylist;

		mylist.push_back (100);
		mylist.push_back (200);
		mylist.push_back (300);

		std::cout << "mylist stores " << mylist.size() << " numbers.\n";
	}
	{
		TITLE_GRN("ft");
		ft::list<int> mylist;
	
		mylist.push_back (100);
		mylist.push_back (200);
		mylist.push_back (300);
	
		std::cout << "mylist stores " << mylist.size() << " numbers.\n";
	}


	TITLE_RED("__POP_BACK__");
	{
		TITLE_GRN("std");
		std::list<int> mylist;
		int sum (0);
		mylist.push_back (100);
		mylist.push_back (200);
		mylist.push_back (300);

		while (!mylist.empty())
		{
			sum+=mylist.back();
			mylist.pop_back();
		}

		std::cout << "The elements of mylist summed " << sum << '\n';
	}
	{
		TITLE_GRN("ft");
		ft::list<int> mylist;
		int sum (0);
		mylist.push_back (100);
		mylist.push_back (200);
		mylist.push_back (300);

		while (!mylist.empty())
		{
			sum+=mylist.back();
			mylist.pop_back();
		}

		std::cout << "The elements of mylist summed " << sum << '\n';
	}

	TITLE_RED("__INSERT__");
	{
		TITLE_GRN("std");
		std::list<int> mylist;
		std::list<int>::iterator it;

		// set some initial values:
		for (int i=1; i<=5; ++i) mylist.push_back(i); // 1 2 3 4 5

		it = mylist.begin();
		++it;       // it points now to number 2           ^

		mylist.insert (it,10);                        // 1 10 2 3 4 5

		// "it" still points to number 2                      ^
		mylist.insert (it,2,20);                      // 1 10 20 20 2 3 4 5

		--it;       // it points now to the second 20            ^

		std::vector<int> myvector (2,30);
		mylist.insert (it,myvector.begin(),myvector.end());
		                                              // 1 10 20 30 30 20 2 3 4 5
		                                              //               ^
		std::cout << "mylist contains:";
		for (it=mylist.begin(); it!=mylist.end(); ++it)
		  std::cout << ' ' << *it;
		std::cout << '\n';
	}
	{
		TITLE_GRN("ft");
		ft::list<int> mylist;
		ft::list<int>::iterator it;

		// set some initial values:
		for (int i=1; i<=5; ++i) mylist.push_back(i); // 1 2 3 4 5

		it = mylist.begin();
		++it;       // it points now to number 2           ^

		mylist.insert (it,10);                        // 1 10 2 3 4 5

		// "it" still points to number 2                      ^
		mylist.insert (it,2,20);                      // 1 10 20 20 2 3 4 5

		--it;       // it points now to the second 20            ^

		std::vector<int> myvector (2,30);
		mylist.insert (it,myvector.begin(),myvector.end());
		                                              // 1 10 20 30 30 20 2 3 4 5
		                                              //               ^
		std::cout << "mylist contains:";
		for (it=mylist.begin(); it!=mylist.end(); ++it)
		  std::cout << ' ' << *it;
		std::cout << '\n';
	}

	TITLE_RED("__ERASE__");
	{
		TITLE_GRN("std");
		std::list<int> mylist;
		std::list<int>::iterator it1,it2;

		// set some values:
		for (int i=1; i<10; ++i) mylist.push_back(i*10);

		                            // 10 20 30 40 50 60 70 80 90
		it1 = it2 = mylist.begin(); // ^^
		std::advance (it2,6);       // ^                 ^
		++it1;                      //    ^              ^

		it1 = mylist.erase (it1);   // 10 30 40 50 60 70 80 90
		                            //    ^           ^

		it2 = mylist.erase (it2);   // 10 30 40 50 60 80 90
		                            //    ^           ^

		++it1;                      //       ^        ^
		--it2;                      //       ^     ^

		mylist.erase (it1,it2);     // 10 30 60 80 90
		                            //        ^

		std::cout << "mylist contains:";
		for (it1=mylist.begin(); it1!=mylist.end(); ++it1)
			std::cout << ' ' << *it1;
		std::cout << '\n';
	}
	{
		TITLE_GRN("ft");
		ft::list<int> mylist;
		ft::list<int>::iterator it1,it2;

		// set some values:
		for (int i=1; i<10; ++i) mylist.push_back(i*10);

		                            // 10 20 30 40 50 60 70 80 90
		it1 = it2 = mylist.begin(); // ^^
		std::advance (it2,6);       // ^                 ^
		++it1;                      //    ^              ^

		it1 = mylist.erase (it1);   // 10 30 40 50 60 70 80 90
		                            //    ^           ^

		it2 = mylist.erase (it2);   // 10 30 40 50 60 80 90
		                            //    ^           ^

		++it1;                      //       ^        ^
		--it2;                      //       ^     ^

		mylist.erase (it1,it2);     // 10 30 60 80 90
		                            //        ^

		std::cout << "mylist contains:";
		for (it1=mylist.begin(); it1!=mylist.end(); ++it1)
			std::cout << ' ' << *it1;
		std::cout << '\n';
	}

	TITLE_RED("__SWAP__");
	{
		TITLE_GRN("std");
		std::list<int> first (3,100);   // three ints with a value of 100
		std::list<int> second (5,200);  // five ints with a value of 200

		first.swap(second);

		std::cout << "first contains:";
		for (std::list<int>::iterator it=first.begin(); it!=first.end(); it++)
			std::cout << ' ' << *it;
		std::cout << '\n';

		std::cout << "second contains:";
		for (std::list<int>::iterator it=second.begin(); it!=second.end(); it++)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	{
		TITLE_GRN("ft");
		ft::list<int> first (3,100);   // three ints with a value of 100
		ft::list<int> second (5,200);  // five ints with a value of 200

		first.swap(second);

		std::cout << "first contains:";
		for (ft::list<int>::iterator it=first.begin(); it!=first.end(); it++)
			std::cout << ' ' << *it;
		std::cout << '\n';

		std::cout << "second contains:";
		for (ft::list<int>::iterator it=second.begin(); it!=second.end(); it++)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}

	TITLE_RED("__RESIZE__");
	{
		TITLE_GRN("std");
		std::list<int> mylist;

		// set some initial content:
		for (int i=1; i<10; ++i) mylist.push_back(i);

		mylist.resize(5);
		mylist.resize(8,100);
		mylist.resize(12);

		std::cout << "mylist contains:";
		for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;

		std::cout << '\n';

	}
	{
		TITLE_GRN("ft");
		ft::list<int> mylist;

		// set some initial content:
		for (int i=1; i<10; ++i) mylist.push_back(i);

		mylist.resize(5);
		mylist.resize(8,100);
		mylist.resize(12);

		std::cout << "mylist contains:";
		for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;

		std::cout << '\n';

	}

	TITLE_RED("__CLEAR__");
	{
		TITLE_GRN("std");
		std::list<int> mylist;
		std::list<int>::iterator it;

		mylist.push_back (100);
		mylist.push_back (200);
		mylist.push_back (300);

		std::cout << "mylist contains:";
		for (it=mylist.begin(); it!=mylist.end(); ++it)
		  std::cout << ' ' << *it;
		std::cout << '\n';

		mylist.clear();
		mylist.push_back (1101);
		mylist.push_back (2202);

		std::cout << "mylist contains:";
		for (it=mylist.begin(); it!=mylist.end(); ++it)
		  std::cout << ' ' << *it;
		std::cout << '\n';
	}
	{
		TITLE_GRN("ft");
		ft::list<int> mylist;
		ft::list<int>::iterator it;

		mylist.push_back (100);
		mylist.push_back (200);
		mylist.push_back (300);

		std::cout << "mylist contains:";
		for (it=mylist.begin(); it!=mylist.end(); ++it)
		  std::cout << ' ' << *it;
		std::cout << '\n';

		mylist.clear();
		mylist.push_back (1101);
		mylist.push_back (2202);

		std::cout << "mylist contains:";
		for (it=mylist.begin(); it!=mylist.end(); ++it)
		  std::cout << ' ' << *it;
		std::cout << '\n';
	}

	TITLE_RED("__SPLICE__");
	{
		TITLE_GRN("std");
		std::list<int> mylist1, mylist2;
		std::list<int>::iterator it;

		// set some initial values:
		for (int i=1; i<=4; ++i)
			mylist1.push_back(i);      // mylist1: 1 2 3 4

		for (int i=1; i<=3; ++i)
			mylist2.push_back(i*10);   // mylist2: 10 20 30

		it = mylist1.begin();
		++it;                         // points to 2

		mylist1.splice (it, mylist2); // mylist1: 1 10 20 30 2 3 4
		                              // mylist2 (empty)
		                              // "it" still points to 2 (the 5th element)

		mylist2.splice (mylist2.begin(),mylist1, it);
		                              // mylist1: 1 10 20 30 3 4
		                              // mylist2: 2
		                              // "it" is now invalid.

		it = mylist1.begin();
		std::advance(it,3);           // "it" points now to 30

		mylist1.splice ( mylist1.begin(), mylist1, it, mylist1.end());
		                              // mylist1: 30 3 4 1 10 20

		std::cout << "mylist1 contains:";
		for (it=mylist1.begin(); it!=mylist1.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		std::cout << "mylist2 contains:";
		for (it=mylist2.begin(); it!=mylist2.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	{
		TITLE_GRN("ft");
		ft::list<int> mylist1, mylist2;
		ft::list<int>::iterator it;

		// set some initial values:
		for (int i=1; i<=4; ++i)
			mylist1.push_back(i);      // mylist1: 1 2 3 4

		for (int i=1; i<=3; ++i)
			mylist2.push_back(i*10);   // mylist2: 10 20 30

		it = mylist1.begin();
		++it;                         // points to 2

		mylist1.splice (it, mylist2); // mylist1: 1 10 20 30 2 3 4
		                              // mylist2 (empty)
		                              // "it" still points to 2 (the 5th element)

		mylist2.splice (mylist2.begin(), mylist1, it);
		                              // mylist1: 1 10 20 30 3 4
		                              // mylist2: 2
		                              // "it" is now invalid.

		it = mylist1.begin();
		std::advance(it,3);           // "it" points now to 30

		mylist1.splice ( mylist1.begin(), mylist1, it, mylist1.end());
		                              // mylist1: 30 3 4 1 10 20

		std::cout << "mylist1 contains:";
		for (it=mylist1.begin(); it!=mylist1.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		std::cout << "mylist2 contains:";
		for (it=mylist2.begin(); it!=mylist2.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}


	TITLE_RED("__REMOVE__");
	{
		TITLE_GRN("std");
		int myints[]= {17,89,7,14};
		std::list<int> mylist (myints,myints+4);

		mylist.remove(89);

		std::cout << "mylist contains:";
		for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	{
		TITLE_GRN("ft");
		int myints[]= {17,89,7,14};
		ft::list<int> mylist (myints,myints+4);

		mylist.remove(89);

		std::cout << "mylist contains:";
		for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}


	TITLE_RED("__REMOVE_IF__");
	{
		TITLE_GRN("std");
		int myints[]= {15,36,7,17,20,39,4,1};
		std::list<int> mylist (myints,myints+8);   // 15 36 7 17 20 39 4 1
		
		mylist.remove_if (single_digit);           // 15 36 17 20 39
		
		mylist.remove_if (is_odd());               // 36 20
		
		std::cout << "mylist contains:";
		for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	{
		TITLE_GRN("ft");
		int myints[]= {15,36,7,17,20,39,4,1};
		ft::list<int> mylist (myints,myints+8);   // 15 36 7 17 20 39 4 1
		
		mylist.remove_if (single_digit);           // 15 36 17 20 39
		
		mylist.remove_if (is_odd());               // 36 20
		
		std::cout << "mylist contains:";
		for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}


	TITLE_RED("__UNIQUE__");
	{
		TITLE_GRN("std");
		double mydoubles[]={ 12.15,  2.72, 73.0,  12.77,  3.14,
		                     12.77, 73.35, 72.25, 15.3,  72.25 };
		std::list<double> mylist (mydoubles,mydoubles+10);
		
		mylist.sort();             //  2.72,  3.14, 12.15, 12.77, 12.77,
		                           // 15.3,  72.25, 72.25, 73.0,  73.35

		mylist.unique();           //  2.72,  3.14, 12.15, 12.77
		                           // 15.3,  72.25, 73.0,  73.35

		mylist.unique (same_integral_part);  //  2.72,  3.14, 12.15
		                                     // 15.3,  72.25, 73.0

		mylist.unique (is_near());           //  2.72, 12.15, 72.25

		std::cout << "mylist contains:";
		for (std::list<double>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	{
		TITLE_GRN("ft");
		double mydoubles[]={ 12.15,  2.72, 73.0,  12.77,  3.14,
		                     12.77, 73.35, 72.25, 15.3,  72.25 };
		ft::list<double> mylist (mydoubles,mydoubles+10);
		
		mylist.sort();             //  2.72,  3.14, 12.15, 12.77, 12.77,
		                           // 15.3,  72.25, 72.25, 73.0,  73.35

		mylist.unique();           //  2.72,  3.14, 12.15, 12.77
		                           // 15.3,  72.25, 73.0,  73.35

		mylist.unique (same_integral_part);  //  2.72,  3.14, 12.15
		                                     // 15.3,  72.25, 73.0

		mylist.unique (is_near());           //  2.72, 12.15, 72.25

		std::cout << "mylist contains:";
		for (ft::list<double>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}


	TITLE_RED("__MERGE__");
	{
		TITLE_GRN("std");
		std::list<double> first, second;

		first.push_back (3.1);
		first.push_back (2.2);
		first.push_back (2.9);

		second.push_back (13.7);
		second.push_back (17.1);
		second.push_back (11.4);

		first.sort();
		second.sort();

		first.merge(second);

		// (second is now empty)

		second.push_back (2.1);

		first.merge(second,mycomparison);

		std::cout << "first contains:";
		for (std::list<double>::iterator it=first.begin(); it!=first.end(); ++it)
		  std::cout << ' ' << *it;
		std::cout << '\n';
	}
	{
		TITLE_GRN("ft");
		ft::list<double> first, second;

		first.push_back (3.1);
		first.push_back (2.2);
		first.push_back (2.9);

		second.push_back (13.7);
		second.push_back (17.1);
		second.push_back (11.4);

		first.sort();
		second.sort();

		first.merge(second);

		// (second is now empty)

		second.push_back (2.1);

		first.merge(second,mycomparison);

		std::cout << "first contains:";
		for (ft::list<double>::iterator it=first.begin(); it!=first.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}


	TITLE_RED("__SORT__");
	{
		TITLE_GRN("std");
		std::list<std::string> mylist;
		std::list<std::string>::iterator it;
		mylist.push_back ("one");
		mylist.push_back ("two");
		mylist.push_back ("Three");

		mylist.sort();

		std::cout << "mylist contains:";
		for (it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		mylist.sort(compare_nocase);

		std::cout << "mylist contains:";
		for (it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	{
		TITLE_GRN("ft");
		ft::list<std::string> mylist;
		ft::list<std::string>::iterator it;
		mylist.push_back ("one");
		mylist.push_back ("two");
		mylist.push_back ("Three");

		mylist.sort();

		std::cout << "mylist contains:";
		for (it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		mylist.sort(compare_nocase);

		std::cout << "mylist contains:";
		for (it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}


	TITLE_RED("__REVERSE__");
	{
		TITLE_GRN("std");
		std::list<int> mylist;

		for (int i=1; i<10; ++i) mylist.push_back(i);

		mylist.reverse();

		std::cout << "mylist contains:";
		for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;

		std::cout << '\n';
	}
	{
		TITLE_GRN("ft");
		ft::list<int> mylist;

		for (int i=1; i<10; ++i) mylist.push_back(i);

		mylist.reverse();

		std::cout << "mylist contains:";
		for (ft::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
			std::cout << ' ' << *it;

		std::cout << '\n';
	}

	return 0;
}