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

#include <stack>
#include <vector>
#include "test.hpp"


void test_stack()
{
    TITLE_MGN("     _             _    ");
    TITLE_MGN(" ___| |_ __ _  ___| | __");
    TITLE_MGN("/ __| __/ _` |/ __| |/ /");
    TITLE_MGN("\\__ \\ || (_| | (__|   < ");
    TITLE_MGN("|___/\\__\\__,_|\\___|_|\\_\\");
                        

    TITLE_RED("__STACK_CONSTRUCTORS__");
    {
        TITLE_GRN("std");
        std::deque<int> mydeque (3,100);          // deque with 3 elements
        std::vector<int> myvector (2,200);        // vector with 2 elements

        std::stack<int> first;                    // empty stack
        std::stack<int> second (mydeque);         // stack initialized to copy of deque

        std::stack<int,std::vector<int> > third;  // empty stack using vector
        std::stack<int,std::vector<int> > fourth (myvector);

        std::cout << "size of first: " << first.size() << '\n';
        std::cout << "size of second: " << second.size() << '\n';
        std::cout << "size of third: " << third.size() << '\n';
        std::cout << "size of fourth: " << fourth.size() << '\n';
    }
    {
        TITLE_GRN("ft");
        std::deque<int> mydeque (3,100);          // deque with 3 elements
        std::vector<int> myvector (2,200);        // vector with 2 elements

        ft::Stack<int,std::deque<int> > first;                    // empty stack
        ft::Stack<int,std::deque<int> > second (mydeque);         // stack initialized to copy of deque

        ft::Stack<int,std::vector<int> > third;  // empty stack using vector
        ft::Stack<int,std::vector<int> > fourth (myvector);

        std::cout << "size of first: " << first.size() << '\n';
        std::cout << "size of second: " << second.size() << '\n';
        std::cout << "size of third: " << third.size() << '\n';
        std::cout << "size of fourth: " << fourth.size() << '\n';
    }

    TITLE_RED("__EMPTY__");
    {
        TITLE_GRN("std");
        std::stack<int> mystack;
        int sum (0);

        for (int i=1;i<=10;i++) mystack.push(i);

        while (!mystack.empty())
        {
            sum += mystack.top();
            mystack.pop();
        }

        std::cout << "total: " << sum << '\n';
    }
    {
        TITLE_GRN("ft");
        ft::Stack<int> mystack;
        int sum (0);

        for (int i=1;i<=10;i++) mystack.push(i);

        while (!mystack.empty())
        {
            sum += mystack.top();
            mystack.pop();
        }

        std::cout << "total: " << sum << '\n';
    }

    TITLE_RED("__SIZE__");
    {
        TITLE_GRN("std");
        std::stack<int> myints;
        std::cout << "0. size: " << myints.size() << '\n';

        for (int i=0; i<5; i++) myints.push(i);
        std::cout << "1. size: " << myints.size() << '\n';

        myints.pop();
        std::cout << "2. size: " << myints.size() << '\n';
    }
    {
        TITLE_GRN("ft");
        ft::Stack<int> myints;
        std::cout << "0. size: " << myints.size() << '\n';

        for (int i=0; i<5; i++) myints.push(i);
        std::cout << "1. size: " << myints.size() << '\n';

        myints.pop();
        std::cout << "2. size: " << myints.size() << '\n';
    }

    TITLE_RED("__TOP__");
    {
        TITLE_GRN("std");
        std::stack<int> mystack;

        mystack.push(10);
        mystack.push(20);

        mystack.top() -= 5;

        std::cout << "mystack.top() is now " << mystack.top() << '\n';
    }
    {
        TITLE_GRN("ft");
        ft::Stack<int> mystack;

        mystack.push(10);
        mystack.push(20);

        mystack.top() -= 5;

        std::cout << "mystack.top() is now " << mystack.top() << '\n';
    }

    TITLE_RED("__PUSH__");
    {
        TITLE_GRN("std");
        std::stack<int> mystack;

        for (int i=0; i<5; ++i) mystack.push(i);

        std::cout << "Popping out elements...";
        while (!mystack.empty())
        {
            std::cout << ' ' << mystack.top();
            mystack.pop();
        }
        std::cout << '\n';
    }
    {
        TITLE_GRN("ft");
        ft::Stack<int> mystack;

        for (int i=0; i<5; ++i) mystack.push(i);

        std::cout << "Popping out elements...";
        while (!mystack.empty())
        {
            std::cout << ' ' << mystack.top();
            mystack.pop();
        }
        std::cout << '\n';
    }

    TITLE_RED("__POP__");
    {
        TITLE_GRN("std");
        std::stack<int> mystack;

        for (int i=0; i<5; ++i) mystack.push(i);

        std::cout << "Popping out elements...";
        while (!mystack.empty())
        {
            std::cout << ' ' << mystack.top();
            mystack.pop();
        }
        std::cout << '\n';
    }
    {
        TITLE_GRN("ft");
        ft::Stack<int> mystack;

        for (int i=0; i<5; ++i) mystack.push(i);

        std::cout << "Popping out elements...";
        while (!mystack.empty())
        {
            std::cout << ' ' << mystack.top();
            mystack.pop();
        }
        std::cout << '\n';
    }
}