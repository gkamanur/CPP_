/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 09:50:50 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/23 12:45:16 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"

Animal::Animal() : _type ("")
{
    Print::print("Animal default constructor called");
}

Animal::Animal(const Animal &src) : _type(src._type)
{
    Print::print("Animal copy constructor called");
    
}

Animal &Animal::operator=(const Animal &rhs)
{
    Print::print("Animal copy assignment operator called");
    if (this != &rhs)
        _type = rhs._type;
    return (*this);
}

Animal::~Animal()
{
    Print::print("Animal destructor called");
}

void Animal::makesound() const
{
    Print::print("Animal makes generic sound.......");
}

std::string Animal::getType() const
{
    return (_type);
}