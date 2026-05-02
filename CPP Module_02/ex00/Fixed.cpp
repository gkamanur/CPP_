/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:13:33 by gkamanur          #+#    #+#             */
/*   Updated: 2026/02/26 18:27:11 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _value(2)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "copy constructor called" <<std::endl;
    *this = other;
}

Fixed &Fixed::operator = (const Fixed &other)
{
    std::cout << "copy assignment operator called" << std::endl;
    if(this != &other)
    {
        this->_value = other.getRawBits();
    }
    return (*this);
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits function called" << std::endl;
    return (this-> _value);
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}