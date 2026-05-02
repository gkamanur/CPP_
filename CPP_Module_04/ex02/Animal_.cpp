/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal_.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 09:50:50 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/23 16:31:45 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal_.hpp"

Animal_::Animal_() : _type ("")
{
    Tracker::animalCtor++;
    Print::print("Animal_ default constructor called");
}

Animal_::Animal_(const Animal_ &src) : _type(src._type)

{
    Tracker::animalCopy++;
    Print::print("Animal_ copy constructor called");
    
}

Animal_ &Animal_::operator=(const Animal_ &rhs)
{
    Print::print("Animal_ copy assignment operator called");
    if (this != &rhs)
        _type = rhs._type;
    return (*this);
}

Animal_::~Animal_()
{
    Tracker::animalDtor++;
    Print::print("Animal_ destructor called");
}

void Animal_::makesound() const
{
    Print::print("Animal_ makes generic sound.......");
}

std::string Animal_::getType() const
{
    return (_type);
}