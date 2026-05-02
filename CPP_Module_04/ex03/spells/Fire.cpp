/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fire.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 13:47:25 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/26 13:50:45 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fire.hpp"
# include "../includes/ICharacter.hpp"

Fire::Fire() : Amateria("fire")
{
}

Fire::Fire(const Fire &src) : Amateria(src)
{
}

Fire &Fire::operator=(const Fire &rhs)
{
    (void)rhs;
    return *this;
}

Fire::~Fire()
{
}

Amateria* Fire::clone() const
{
    return new Fire(*this);
}

void Fire::use(ICharacter &target)
{
    Print::print("* throws fireball at " + target.getName() + " *");
}