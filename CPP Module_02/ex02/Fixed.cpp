/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:02:09 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/06 18:54:59 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

Fixed::Fixed(void) : _value(0){}

Fixed::Fixed(const int n) : _value(n << _fractionalBits){}

Fixed::Fixed(const float f) : _value(round(f * (1 << _fractionalBits))){}

Fixed::Fixed(const Fixed &other)
{
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        this->_value = other.getRawBits();
    return (*this);
}

Fixed::~Fixed(void){}

// Conversion Functions

float Fixed::toFloat(void) const
{
    return ((float)this->_value / (float) (1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
    return (this->_value >> _fractionalBits);
}

int Fixed::getRawBits(void) const
{
    return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}

// Comparision operators

bool Fixed::operator>(const Fixed &other) const
{
    return(this->_value > other._value);
}

bool Fixed::operator<(const Fixed &other) const
{
    return(this->_value < other._value);
}

bool Fixed::operator>=(const Fixed &other) const
{
    return(this->_value >= other._value);
}

bool Fixed::operator<=(const Fixed &other) const
{
    return(this->_value <= other._value);
}

bool Fixed::operator==(const Fixed &other) const
{
    return(this->_value == other._value);
}

bool Fixed::operator!=(const Fixed &other) const
{
    return(this->_value != other._value);
}

//Arithematic operators

Fixed Fixed::operator+(const Fixed &other) const
{
    return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other) const
{
    return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other) const
{
    return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const
{
    return (Fixed(this->toFloat() / other.toFloat()));
}

//increment/ decrement

Fixed &Fixed::operator++(void)
{
    this->_value++;
    return(*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    this->_value++;
    return(temp);
}

Fixed &Fixed::operator--(void)
{
    this->_value--;
    return(*this);
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    this->_value--;
    return(temp);
}

//static min max

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return( a < b ? a : b);
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return( a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return( a < b ? b : a);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return( a < b ? b : a);
}

//stream insertion

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return os;
}
