/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 11:59:03 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/23 12:35:35 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "WrongCat.hpp"

WrongCat::WrongCat()
{
    Print::print("WrongCat default constructor called");
    _type = "WrongCat";
}
WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src)
{
    Print::print("WrongCat copy constructor");
}
WrongCat &WrongCat::operator=(const WrongCat &rhs)
{
    Print::print ("WrongCat copy assignment operator");
    if (this != &rhs)
        WrongAnimal::operator=(rhs);
    return (*this);
}

WrongCat::~WrongCat()
{
    Print::print("WrongCat destructor called");
}

void WrongCat::makesound() const
{
    Print::print ("WrongCat Meow! Meow!");
}