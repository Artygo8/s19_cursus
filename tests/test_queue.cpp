
#include <list>
#include <queue>
#include "test.hpp"


void test_queue()
{
    TITLE_MGN("                             ");
    TITLE_MGN("  __ _ _   _  ___ _   _  ___ ");
    TITLE_MGN(" / _` | | | |/ _ \\ | | |/ _ \\");
    TITLE_MGN("| (_| | |_| |  __/ |_| |  __/");
    TITLE_MGN(" \\__, |\\__,_|\\___|\\__,_|\\___|");
    TITLE_MGN("    |_|                      ");

    TITLE_RED("__QUEUE_CONSTRUCTORS__");
    {
        TITLE_GRN("std");
        std::deque<int> mydeck (3,100);        // deque with 3 elements
        std::list<int> mylist (2,200);         // list with 2 elements

        std::queue<int> first;                 // empty queue
        std::queue<int> second (mydeck);       // queue initialized to copy of deque

        std::queue<int,std::list<int> > third; // empty queue with list as underlying container
        std::queue<int,std::list<int> > fourth (mylist);

        std::cout << "size of first: " << first.size() << '\n';
        std::cout << "size of second: " << second.size() << '\n';
        std::cout << "size of third: " << third.size() << '\n';
        std::cout << "size of fourth: " << fourth.size() << '\n';
    }
    {
        TITLE_GRN("ft");
        std::deque<int> mydeck (3,100);        // deque with 3 elements
        std::list<int> mylist (2,200);         // list with 2 elements

        ft::queue<int,std::deque<int> > first;                 // empty queue
        ft::queue<int,std::deque<int> > second (mydeck);       // queue initialized to copy of deque

        ft::queue<int,std::list<int> > third; // empty queue with list as underlying container
        ft::queue<int,std::list<int> > fourth (mylist);

        std::cout << "size of first: " << first.size() << '\n';
        std::cout << "size of second: " << second.size() << '\n';
        std::cout << "size of third: " << third.size() << '\n';
        std::cout << "size of fourth: " << fourth.size() << '\n';
    }

    TITLE_RED("__EMPTY__");
    {
        TITLE_GRN("std");
        std::queue<int> myqueue;
        int sum (0);

        for (int i=1;i<=10;i++) myqueue.push(i);

        while (!myqueue.empty())
        {
            sum += myqueue.front();
            myqueue.pop();
        }

        std::cout << "total: " << sum << '\n';
    }
    {
        TITLE_GRN("ft");
        ft::queue<int> myqueue;
        int sum (0);

        for (int i=1;i<=10;i++) myqueue.push(i);

        while (!myqueue.empty())
        {
            sum += myqueue.front();
            myqueue.pop();
        }

        std::cout << "total: " << sum << '\n';
    }

    TITLE_RED("__SIZE__");
    {
        TITLE_GRN("std");
        std::queue<int> myints;
        std::cout << "0. size: " << myints.size() << '\n';

        for (int i=0; i<5; i++) myints.push(i);
        std::cout << "1. size: " << myints.size() << '\n';

        myints.pop();
        std::cout << "2. size: " << myints.size() << '\n';
    }
    {
        TITLE_GRN("ft");
        ft::queue<int> myints;
        std::cout << "0. size: " << myints.size() << '\n';

        for (int i=0; i<5; i++) myints.push(i);
        std::cout << "1. size: " << myints.size() << '\n';

        myints.pop();
        std::cout << "2. size: " << myints.size() << '\n';
    }

    TITLE_RED("__FRONT__");
    {
        TITLE_GRN("std");
        std::queue<int> myqueue;

        myqueue.push(77);
        myqueue.push(16);

        myqueue.front() -= myqueue.back();    // 77-16=61

        std::cout << "myqueue.front() is now " << myqueue.front() << '\n';
    }
    {
        TITLE_GRN("ft");
        ft::queue<int> myqueue;

        myqueue.push(77);
        myqueue.push(16);

        myqueue.front() -= myqueue.back();    // 77-16=61

        std::cout << "myqueue.front() is now " << myqueue.front() << '\n';
    }

    TITLE_RED("__BACK__");
    {
        TITLE_GRN("std");
        std::queue<int> myqueue;

        myqueue.push(12);
        myqueue.push(75);   // this is now the back

        myqueue.back() -= myqueue.front();

        std::cout << "myqueue.back() is now " << myqueue.back() << '\n';
    }
    {
        TITLE_GRN("ft");
        ft::queue<int> myqueue;

        myqueue.push(12);
        myqueue.push(75);   // this is now the back

        myqueue.back() -= myqueue.front();

        std::cout << "myqueue.back() is now " << myqueue.back() << '\n';
    }

    TITLE_RED("__PUSH / POP__");
    {
        TITLE_GRN("std");
        std::queue<int> myqueue;

        for (int i = 0; i < 5; ++i)
            myqueue.push (i);

        std::cout << "myqueue contains: ";
        while (!myqueue.empty())
        {
            std::cout << ' ' << myqueue.front();
            myqueue.pop();
        }
        std::cout << '\n';
    }
    {
        TITLE_GRN("ft");
        ft::queue<int> myqueue;

        for (int i = 0; i < 5; ++i)
            myqueue.push (i);

        std::cout << "myqueue contains: ";
        while (!myqueue.empty())
        {
            std::cout << ' ' << myqueue.front();
            myqueue.pop();
        }
        std::cout << '\n';
    }
}