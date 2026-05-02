/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:51:01 by gkamanur          #+#    #+#             */
/*   Updated: 2026/02/19 15:05:01 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) : _name("unnamed")
{
   std::cout << " unnamed constructor" << std::endl;
}


Zombie::Zombie(std::string name) : _name(name) 
{
    std::cout << " Named constructor" << std::endl;
}

// Destructor - prints when each zombie dies
Zombie::~Zombie(void) 
{
    std::cout << this->_name << " is destroyed!" << std::endl;
}

// Set the zombie's name (needed for array allocation)
void Zombie::setName(std::string name) 
{
    this->_name = name;
}

// The zombie announces itself
void Zombie::announce(void) 
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
