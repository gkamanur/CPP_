/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 19:31:04 by gkamanur          #+#    #+#             */
/*   Updated: 2026/04/07 14:59:43 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
What is Serialization?
Serialization is converting a complex data structure (like a pointer) into a format that can be stored or transmitted.

In this exercise:

A pointer stores a memory address (where data lives)
uintptr_t is an unsigned integer type that can hold a pointer
You convert pointer → integer (serialize)
Then integer → pointer (deserialize)
*/

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <iostream>
#include "Data.hpp"

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer& other);
        Serializer& operator=(const Serializer& rhs);
        ~Serializer();
    public:
        static uintptr_t serialize(Data *ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif