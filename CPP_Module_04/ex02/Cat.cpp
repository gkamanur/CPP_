/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 11:13:11 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/23 19:25:03 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"

Cat::Cat() : _brain(new Brain())
{
    Tracker::catCtor++;
    Print::print("Cat Default constructor called");
    _type = "Cat";
}

Cat::Cat(const Cat &src) : Animal_(src), _brain(new Brain(*src._brain))
{
    Tracker::catCopy++;
    Print::print("Cat copy constructor called");
}

Cat &Cat::operator=(const Cat &rhs)
{
    Print::print("Cat copy siignment operator called");
    if (this != &rhs)
    {
        Animal_::operator=(rhs);
        delete _brain;
        _brain = new Brain(*rhs._brain);
    }
    return (*this);
}

Cat::~Cat()
{
    Tracker::catDtor++;
    Print::print("Cat destructor called");
    delete _brain;
}

void Cat::makesound() const
{
    Print::print("Meow! Meow!!");
}

Brain* Cat::getBrain() const
{
    return (_brain);
}