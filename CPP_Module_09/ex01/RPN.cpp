/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 18:13:20 by gkamanur          #+#    #+#             */
/*   Updated: 2026/04/27 19:30:30 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>
#include <stdexcept>
#include <cctype>

RPN::RPN() {}
RPN::RPN(const RPN& other) : _stack(other._stack){}
RPN& RPN::operator=(const RPN& rhs)
{
    if(this != &rhs)
        _stack = rhs._stack;
    return (*this);
}

RPN::~RPN(){}

bool RPN::_isoperator(char c) const
{
    return( c == '+' || c == '-' || c == '*' || c == '/');
}

int RPN::_applyOp(int a, int b, char op) const
{
    switch (op)
    {
        case '+': return (a + b);
        case '-': return (a - b);
        case '*': return (a * b);
        case '/': 
            if (b == 0)
                throw std::runtime_error("ERROR: denominator is 0"); 
            return (a / b);
    }
    throw std::runtime_error("Error: look to applyOp");
}

int RPN::evaluate(const std::string& expression)
{
    while (!_stack.empty())
        _stack.pop();
    std::istringstream iss(expression);
    std::string token;
    
    while (iss >> token)
    {
        if (token.size() == 1 && _isoperator(token[0]))
        {
            if (_stack.size() < 2)
                throw std::runtime_error("ERROR in Evaluate");
            int b = _stack.top(); _stack.pop();
            int a = _stack.top(); _stack.pop();
            _stack.push(_applyOp(a, b, token[0]));
        }
        else if (token.size() == 1
            && std::isdigit(static_cast<unsigned char>(token[0])))
        {
            _stack.push(token[0] - '0');
        }
        else
            throw std::runtime_error("Error - In Evalaute - - -");
    }

    if (_stack.size() != 1)
        throw std::runtime_error("Error");
    
    return _stack.top();
}