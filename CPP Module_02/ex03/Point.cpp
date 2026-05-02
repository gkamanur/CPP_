/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:54:56 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/10 15:07:05 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Point.hpp"

Point::Point(void) : _x(0), _y(0){}

Point::Point(const float x, const float y): _x(x), _y(y){}

Point::Point(const Point &other) : _x(other._x), _y(other._y){}

Point &Point::operator=(const Point &other)
{
    (void)other;
    return (*this);
}

Point::~Point(void){}

const Fixed &Point::getX(void) const
{
    return(this->_x);
}

const Fixed &Point::getY(void) const
{
    return(this->_y);
}
  