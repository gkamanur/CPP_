/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 11:47:47 by gkamanur          #+#    #+#             */
/*   Updated: 2026/04/20 17:58:04 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

void testBasic()
{
    std::cout << std::endl << "=====Basic Tests======" << std::endl;
    
    Span sp = Span(5);
    sp.addNum(6);
    sp.addNum(3);
    sp.addNum(17);
    sp.addNum(9);
    sp.addNum(11);

    std::cout << "Numbers in span: ";
    const std::vector<int>& nums = sp.getNums();
    for (size_t i = 0; i < nums.size(); i++)
    {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
    std::cout << "longestSpan : " << sp.longestSpan() << std::endl;
}
void testException()
{
    std::cout << std::endl << "=======Exception Tests======" << std::endl;
    Span sp(3);
    
    try
    {
        sp.addNum(1);
        sp.addNum(2);
        sp.addNum(3);
        sp.addNum(4);
        
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception caught (AddNumber): " << e.what() << std::endl;
    }
    const std::vector<int>& nums = sp.getNums();
    for (size_t i = 0; i < nums.size(); i++)
    {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
    
    Span empty(5);
    try
    {
        empty.shortestSpan();
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception caught ShortestSpan: " << e.what() << '\n';
    }
    try
    {
        empty.longestSpan();
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception caught LongestSpan: " << e.what() << '\n';
    }
    
    Span one(5);
    one.addNum(42);

    try 
    {
        one.shortestSpan();
    } catch (const std::exception& e) 
    {
        std::cout << "Exception caught (shortestSpan on single element): " << e.what()
            << std::endl;
    }
}

void testRangeAddition()
{
    std::cout << std::endl << "======Range Addition Tests=====" << std::endl;

    std::vector <int> vec;
    for (int i = 0; i < 10; i++)
    {
        vec.push_back(i * 10);
    }
    Span sp(10);
    sp.addNumbers(vec.begin(), vec.end());

    std::cout << "Added 10 numbers via range: ";
    const std::vector<int>& nums = sp.getNums();
    for (size_t i = 0; i < nums.size(); i++)
        std::cout << nums[i] << " ";
    std::cout << std::endl;

    std::cout << "Shortest Span : " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span  : " << sp.longestSpan() << std::endl;    
    
}

void testlargenumbers()
{
    std::cout << "=======Large numbers test - 10,000=======" << std::endl;
    std::srand(std::time(NULL));
    Span sp(10000);

    std::vector<int> numbers;
    for (int i = 0; i < 10000; i++)
        numbers.push_back(std::rand() % 10000);
    
    sp.addNumbers(numbers.begin(), numbers.end());
    
    std::cout << "Added 10,000 random numbers" << std::endl;
    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span:  " << sp.longestSpan() << std::endl;
}

void testEdgecases()
{
    std::cout << std::endl << "======Edge cases=======" << std::endl;

    Span sp(5);
    sp.addNum(100);
    sp.addNum(1);
    sp.addNum(50);
    sp.addNum(0);
    sp.addNum(-2);
    
    std::cout << "Numbers: ";
    const std::vector<int>& nums = sp.getNums();
    for (size_t i = 0; i < nums.size(); i++)
        std::cout << nums[i] << " ";
    std::cout << std::endl;
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    
    Span same(5);
    same.addNum(5);
    same.addNum(5);
    same.addNum(5);
    same.addNum(5);
    same.addNum(5);
    
    std::cout << "All same numbers - shortest span: " << same.shortestSpan() << std::endl;
    std::cout << "All same numbers - longest span: " << same.longestSpan() << std::endl;
}
int main() {
    std::cout << "=== Span Tests ===" << std::endl;
    
    testBasic();
    testException();
    testRangeAddition();
    testlargenumbers();
    testEdgecases();
    return 0;
}