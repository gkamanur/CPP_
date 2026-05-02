/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 19:39:14 by gkamanur          #+#    #+#             */
/*   Updated: 2026/04/07 14:44:58 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Serializer.hpp"

Serializer::Serializer(){}
Serializer::Serializer(const Serializer&){}
Serializer& Serializer::operator=(const Serializer&)
{
    return *this;
}
Serializer::~Serializer(){}

uintptr_t Serializer::serialize(Data *ptr)
{
    //tells the compiler that treat this pointer as an integer
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}
