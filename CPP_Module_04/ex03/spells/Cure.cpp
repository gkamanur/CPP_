/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 16:53:23 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/25 18:58:23 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cure.hpp"
# include "../includes/ICharacter.hpp"
Cure::Cure() :Amateria("cure"){}

Cure::Cure(const Cure &src) : Amateria(src){}

Cure &Cure::operator=(const Cure &rhs)
{
    (void)rhs;
    return *this;
}

Cure::~Cure(){};

Amateria* Cure::clone() const{
    return (new Cure (*this));
}

void Cure::use(ICharacter &target)
{
    Print::print("* heals " + target.getName() + "'s wounds *");
}