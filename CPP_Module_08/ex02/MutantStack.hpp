/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:15:33 by gkamanur          #+#    #+#             */
/*   Updated: 2026/04/21 19:26:06 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <iterator>

// T = what you store
// container = how you store it

template <typename T, typename container = std::deque<T> >
class MutantStack : public std::stack <T, container>
{
public:
    MutantStack() : std::stack<T, container>(){}
    MutantStack(const MutantStack& other) : std::stack <T, container>(other){}
    MutantStack& operator=(const MutantStack& rhs)
    {
        if (this != &rhs)
            std::stack<T, container>::operator=(rhs);
        return (*this);
    }
    ~MutantStack(){}
    
    typedef typename container::iterator iterator;
    typedef typename container::const_iterator const_iterator;
    typedef typename container::reverse_iterator reverse_iterator;
    typedef typename container::const_reverse_iterator const_reverse_iterator;

    iterator begin()
    {
        return(this->c.begin());
    }

    iterator end()
    {
        return(this->c.end());
    }

    const_iterator begin() const
    {
        return(this->c.begin());
    }
    
    const_iterator end() const
    {
        return(this->c.end());
    }  
    
    reverse_iterator rbegin()
    {
        return this->c.rbegin();
    }

    reverse_iterator rend()
    {
        return this->c.rend();
    }
    
    const_reverse_iterator rbegin() const
    {
        return this->c.rbegin();
    }

    const_reverse_iterator rend() const
    {
        return this->c.rend();
    }
};
#endif