/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 18:15:02 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/19 19:29:03 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), FragTrap(), ScavTrap()
{
    _name = "default";
    _hitPoints = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name)
    : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
   _name = name;
   _hitPoints = FragTrap::_hitPoints;
   _energyPoints = ScavTrap::_energyPoints;
   _attackDamage = FragTrap::_attackDamage;
   std::cout <<"DiamondTrap Parametarized constructor called for " << _name << std::endl; 
}

DiamondTrap::DiamondTrap(const DiamondTrap &src)
{
    _name = src._name;
    std::cout << "DiamnonTrap copy constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
{
    std::cout << "DiamondTrap copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        ClapTrap::operator=(rhs);
        _name = rhs._name;
    }
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamonTrap destructor called for " << _name << std::endl;
}

void DiamondTrap::whoAmi()
{
    std::cout << "I am DiamondTrap " << _name
        << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}