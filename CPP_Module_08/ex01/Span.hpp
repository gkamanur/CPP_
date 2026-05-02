/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 14:47:44 by gkamanur          #+#    #+#             */
/*   Updated: 2026/04/18 11:31:38 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <stdexcept>
# include <algorithm>
# include <climits>
# include <iostream>


class Span
{
    private:
        unsigned int _maxSize;
        std::vector<int> _numbers;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& rhs);
        ~Span();
        
        void addNum(int num);
        int shortestSpan() const;
        int longestSpan() const;

        template <typename InputIterator>
        void addNumbers(InputIterator begin, InputIterator end);

        const std::vector<int>& getNums() const;
        unsigned int getMaxSize() const;
        unsigned int getCurrSize() const;  
};

template <typename InputIterator>
void Span::addNumbers(InputIterator begin, InputIterator end)
{
    while (begin != end)
    {
        addNum(*begin);
        ++begin;
    }
}
# endif
