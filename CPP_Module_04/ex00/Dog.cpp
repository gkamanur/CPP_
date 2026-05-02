/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 11:20:44 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/23 12:47:48 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"

Dog::Dog()
{
    Print::print("Dog default constructor called");
    _type = "Dog";
}

Dog::Dog(const Dog &src) : Animal(src)
{
    Print::print("Dog copy constructor called");
}

Dog &Dog::operator=(const Dog &rhs)
{
    Print::print("Dog copy assignment operator called");
    if(this != &rhs)
        Animal::operator=(rhs);
    return (*this);
}

Dog::~Dog()
{
    Print::print("Dog Destructor called");
}

void Dog::makesound() const
{
    Print::print("Woof! Woof!");
}