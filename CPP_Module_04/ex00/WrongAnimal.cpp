/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WromgAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 11:45:11 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/23 12:44:03 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type()
{
    Print::print("wrongAnimal default constructor called");
}

WrongAnimal::WrongAnimal(const WrongAnimal &src) : _type(src._type)
{
    Print::print( "WrongAnimal copy constructor called");
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs)
{
    Print::print("WrongAnimal copy assignment operator called");
    if (this != &rhs)
    {
        _type = rhs._type;
    }
    return(*this);
}

WrongAnimal::~WrongAnimal()
{
    Print::print("WrongAnimal Destructor called");
}

void WrongAnimal::makesound() const
{
    Print::print("WrongAnimal makes Wrong sound.......");
}

std::string WrongAnimal::getType() const
{
    return _type;
}