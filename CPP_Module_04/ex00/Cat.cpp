/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 11:13:11 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/23 12:45:25 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"

Cat::Cat()
{
    Print::print("Cat Default constructor called");
    _type = "Cat";
}

Cat::Cat(const Cat &src) : Animal(src)
{
    Print::print("Cat copy constructor called");
}

Cat &Cat::operator=(const Cat &rhs)
{
    Print::print("Cat copy siignment operator called");
    if (this != &rhs)
        Animal::operator=(rhs);
    return (*this);
}

Cat::~Cat()
{
    Print::print("Cat destructor called");
}

void Cat::makesound() const
{
    Print::print("Meow! Meow!!");
}