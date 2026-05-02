/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 14:10:03 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/23 16:03:05 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Brain.hpp"

Brain::Brain()
{
    Print::print("Brain Default constructor called");
}

Brain::Brain(const Brain &src)
{
    Print::print ("Brain copy constructor called");
    for (int i = 0; i < 100 ; i++)
    {
        ideas[i] = src.ideas[i];
    }
}

Brain &Brain::operator=(const Brain &rhs)
{
    Print::print("Brain copy assignment operator called");
    if (this != &rhs)
    {
        for (int i = 0; i < 100; i++)
            ideas[i] = rhs.ideas[i];
    }
    return (*this);
}

Brain::~Brain()
{
    Print::print("Brain Destructor called");
}