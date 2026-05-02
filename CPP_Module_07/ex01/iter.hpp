/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 11:15:54 by gkamanur          #+#    #+#             */
/*   Updated: 2026/04/16 15:59:43 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP
# include <iostream>

template <typename T>
void iter(T *array, size_t length, void (*func)(T&))
{
    for (size_t i = 0; i < length; i++)
    {
        func(array[i]);
    }
}

template <typename T>
void iter(const T* array, const size_t len, void (*func)(const T&))
{
    for (size_t i = 0; i < len; i++)
        func(array[i]);
}

template <typename T>
void print(T& x)
{
    std::cout << x << " ";
}

template <typename T>
void increment(T& x)
{
    x++;
}
#endif