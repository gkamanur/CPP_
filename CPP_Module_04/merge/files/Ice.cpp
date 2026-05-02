/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 16:34:55 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/24 16:40:24 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Ice.hpp"

Ice::Ice() : Amateria("ice"){}

Ice::Ice(const Ice &src) : Amateria(src){}

Ice &Ice::operator=(const Ice &rhs)
{
    (void) rhs;
    return *this;
}

Ice::~Ice(){}

Amateria* Ice::clone() const
{
    return(new Ice (*this));
}

void Ice::use(ICharacter &target)
{
    Print::print("* shoots an ice bolt at " + target.getName() + " *");
}