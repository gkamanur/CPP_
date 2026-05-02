/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:25:20 by gkamanur          #+#    #+#             */
/*   Updated: 2026/02/19 17:25:23 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}

HumanB::~HumanB(void) {}

void HumanB::setWeapon(Weapon& weapon)
{
    this->_weapon = &weapon;
}

void HumanB::attack(void) const 
{
    if (this->_weapon)
    {  // Check if we have a weapon (not NULL)
        std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
    } 
    else 
    {
        std::cout << this->_name << " has no weapon to attack with!" << std::endl;
    }
}
