/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 18:05:28 by gkamanur          #+#    #+#             */
/*   Updated: 2026/02/26 18:31:40 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int                 _value;
    static const int    _fractionalBits = 8;
    
public:
    Fixed();
    Fixed(const Fixed &other);
    Fixed &operator = (const Fixed &other);
    ~Fixed();
    
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif