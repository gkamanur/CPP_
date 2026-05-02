/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Amateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 11:50:57 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/24 15:18:53 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Amateria.hpp"

Amateria::Amateria() : _type("default"){}
Amateria::Amateria(std::string const &type) : _type(type){}
Amateria::Amateria(const Amateria &src) : _type(src._type){}

Amateria &Amateria::operator=(const Amateria &rhs)
{
    (void)rhs;
    return *this;
}

Amateria::~Amateria(){}

std::string const &Amateria::getType() const
{
    return (_type);
}

void Amateria::use(ICharacter &target)
{
    (void)target;
}
