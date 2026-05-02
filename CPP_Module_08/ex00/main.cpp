/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:33:17 by gkamanur          #+#    #+#             */
/*   Updated: 2026/04/22 18:44:04 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

////////////////////////////////////////////////////////////////////////////
// | Feature          | Vector       | List             | Deque            |
// | ---------------- | -------------| ---------------- | -----------------|
// | Memory layout    | Contiguous   | Non-contiguous   | Semi-contiguous  |
// | Index access     | ✅ Fast (O1) | ❌ Not supported | ✅ Fast (O1)     |
// | Insert front     | ❌ Slow      | ✅ Fast          | ✅ Fast          |
// | Insert middle    | ❌ Slow      | ✅ Fast          | ❌ Slow          |
// | Insert end       | ✅ Fast      | ✅ Fast          | ✅ Fast          |
// | Cache efficiency | ✅ High      | ❌ Low           | ⚠️ Medium        |
////////////////////////////////////////////////////////////////////////////

void testVector()
{
    std::cout << "\n===Testing std::vector=====\n";
    std::vector <int> vec;
    for (int i = 0; i < 10; i++)
        vec.push_back(i * 2);
    
    std::cout << "Vector contents: ";
    for (std::vector <int>::iterator it = vec.begin(); it != vec.end(); ++it)
        std::cout << *it << " ";
    std::cout <<std::endl;
    
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 6);
        std::cout << "Found value 6 at position: " << std::distance(vec.begin(), it) 
                << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: "<< e.what() << '\n';
    }
    try
    {
        std::vector<int>::iterator it = easyfind(vec,7);
        std::cout << "Found value 7 at position: " << std::distance(vec.begin(), it) 
                << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: "<< e.what() << '\n';
    }   
}

void testList()
{
    std::cout << "\n====Testing std::list=====\n";
    std::list<int> lst;
    for (int i = 0; i < 10; i++)
    {
        lst.push_back(i * 3);
    }
    std::cout << "list contents: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    try
    {
        std::list<int>::iterator it = easyfind(lst, 12);
        std::cout << "Found value 12: " << std::distance(lst.begin(), it) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: "<< e.what() << '\n';
    }
    
    try
    {
        std::list<int>::iterator it = easyfind(lst, 5);
        std::cout << "Found value 5: " << std::distance(lst.begin(), it) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: "<< e.what() << '\n';
    }
}

void testDeque()
{
    std::cout << "\n====Testing std::deque====\n";
    std::deque<int> deq;
    for (int i = 0;i < 10;i++)
        deq.push_back(i * 4);
    for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    try 
    {
        std::deque<int>::iterator it = easyfind(deq, 16);
        std::cout << "Found value 16: " << std::distance(deq.begin(), it) << std::endl;
    } catch (const std::exception& e) 
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    try 
    {
        std::deque<int>::iterator it = easyfind(deq, 99);
        std::cout << "Found value 99: " << std::distance(deq.begin(), it) << std::endl;
    } catch (const std::exception& e) 
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void testconstContainer()
{
    std::cout << std::endl << "====Testing Const container=====" << std::endl;
    std::vector<int> vec;
    for (int i = 0; i < 5; i++)
    {
        vec.push_back(i * 5);
    }
    const std::vector<int>& constvec = vec;
    for (int i = 0; i < 5; i++)
    {
        std::cout << constvec[i] << " ";
    }
    try
    {
        std::vector<int>:: const_iterator it = easyfind(constvec, 15);
        std::cout << std::endl << "Found value 15 in const container: " << 
            std::distance(constvec.begin(), it) << std::endl;  
    } 
    catch (const std::exception& e)
    {
        std::cout << "ERROR: " << e.what() << std::endl;
    }
}

void testemptyContainer()
{
    std::cout << std::endl << "====Testing Const container=====" << std::endl;
    std::vector<int> emp;

    try
    {
        std::vector<int>:: const_iterator it = easyfind(emp, 42);
        std::cout << "Found value 42 in const container" << *it << std::endl;  
    } 
    catch (const std::exception& e)
    {
        std::cout << "ERROR: " << e.what() << std::endl;
    }
}

int main ()
{
    std::cout << "=====Easyfind Tests========" << std::endl;
    testVector();
    testList();
    testDeque();
    testconstContainer();
    testemptyContainer();
    
    return (0);
}
