/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 10:58:52 by gkamanur          #+#    #+#             */
/*   Updated: 2026/04/11 11:02:58 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP
#include <iostream>

template <typename T>
void swap (T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T min(const T& a, const T& b)
{
    if (a < b)
        return a;
    else 
        return b;
}

template <typename T>
T max(const T& a, const T& b)
{
    if (a > b)
        return a;
    else 
        return b;
}

#endif