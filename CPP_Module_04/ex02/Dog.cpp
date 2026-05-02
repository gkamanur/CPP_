/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 11:20:44 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/23 19:23:51 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"

Dog::Dog() : _brain(new Brain())
{
    Tracker::dogCtor++;
    Print::print("Dog default constructor called");
    _type = "Dog";
}

Dog::Dog(const Dog &src) : Animal_(src), _brain(new Brain(*src._brain))
{
    Tracker::dogCopy++;
    Print::print("Dog copy constructor called");
}

Dog &Dog::operator=(const Dog &rhs)
{
    Print::print("Dog copy assignment operator called");
    if(this != &rhs)
    {
        Animal_::operator=(rhs);
        delete _brain;
        _brain = new Brain(*rhs._brain);
    }
    return (*this);
}

Dog::~Dog()
{
    Tracker::dogDtor++;
    Print::print("Dog Destructor called");
    delete _brain;
}

void Dog::makesound() const
{
    Print::print("Woof! Woof!");
}

Brain*  Dog::getBrain() const
{
    return (_brain);
}