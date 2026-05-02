/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:35:35 by gkamanur          #+#    #+#             */
/*   Updated: 2026/04/21 19:39:25 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <vector>


void basicTest()
{
    std::cout << std::endl << "=====Basic Tests======" <<std::endl;
    
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    mstack.push(37);
    mstack.push(97);
    mstack.push(23);

    std::cout << "Top elements: " << mstack.top() <<std::endl;
    std::cout << "Size        : " << mstack.size() << std::endl;

    mstack.pop();
    std::cout << "After pop, top: " << mstack.top() <<std::endl;
    std::cout << "Size          : " << mstack.size() << std::endl;
    
    std::cout << "Iterating through stack: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void testReverseIterators()
{
    std::cout << std::endl << "=====Reverse Iterator Tests=====" << std::endl;
    
    MutantStack<int> mstack;
    for (int i = 1; i <= 5; i++)
        mstack.push(i * 10);
    
    std::cout << "Forward: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    std::cout << "Reverse: ";
    for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
        
}

void testConstIterators()
{
    std::cout << std::endl;
    std::cout << "=======Const Iterators Test=======" << std::endl;

    MutantStack<int> mstack;
    for(int i = 1; i <= 5; i++)
        mstack.push(i);
    
    const MutantStack<int>& const_stack = mstack;
    std::cout << "const Forward: ";
    for (MutantStack<int>::const_iterator it = const_stack.begin(); it != const_stack.end(); ++it)
        std::cout << *it << " ";
    std::cout <<std::endl;

    std::cout << "const Reverse: ";
    for (MutantStack<int>::const_reverse_iterator it = const_stack.rbegin(); it != const_stack.rend(); ++it)
        std::cout << *it << " ";
    std::cout <<std::endl; 
}

void main_subject()
{
    std::cout << std::endl;
    std::cout << "=======Subject main  Test=======" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Stack Size: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    // ++it;
    // --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    std::cout << "Stack top element: " << s.top() << std::endl;
}

int main() 
{
     
    std::cout << "=== MutantStack Tests ===" << std::endl;
    
    basicTest();
    testReverseIterators();
    main_subject();
    
    return 0;
}