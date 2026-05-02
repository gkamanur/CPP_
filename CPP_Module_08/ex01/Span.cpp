/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 15:06:41 by gkamanur          #+#    #+#             */
/*   Updated: 2026/04/20 17:58:13 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int N) : _maxSize(N)
{
    _numbers.reserve(N);
}
Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers){}

Span& Span::operator=(const Span& rhs)
{
    if (this != &rhs)
    {
        _maxSize = rhs._maxSize;
        _numbers = rhs._numbers;
    }
    return *this;
}

Span::~Span(){}

void Span::addNum(int num)
{
    if(_numbers.size() >= _maxSize)
        throw std::out_of_range("Span is full, cannot add more...");
    _numbers.push_back(num);
}

int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw std::logic_error("Not enough elements to find a span");
    
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    
    std::cout << std::endl;
    for (size_t i = 0; i < sorted.size(); i++)
        std::cout << sorted[i] << "  ";
    std::cout << std::endl;
    
    int minspan = INT_MAX;
    for (size_t i = 1; i < sorted.size(); i++)
    {
        int span = sorted[i] - sorted[i - 1];
        if(span < minspan)
            minspan = span;
    }
    return (minspan);
}

int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw std::logic_error("Not enough elements to find span");
    
    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());

    return (max - min);
}

const std::vector<int>& Span::getNums() const
{
    return _numbers;
}

unsigned int Span::getMaxSize() const 
{
    return _maxSize;
}

unsigned int Span::getCurrSize() const
{
    return _numbers.size();
}
