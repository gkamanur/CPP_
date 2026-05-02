/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 16:52:29 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/19 15:19:34 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap default constrctor called " << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap Parameterized constructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = src;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
    std::cout << "ClapTrap copy assignment operator" << std::endl;
    if (this != &rhs)
    {
        _name = rhs._name;
        _hitPoints = rhs._hitPoints;
        _energyPoints = rhs._energyPoints;
        _attackDamage = rhs._attackDamage;        
    }
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor called " << _name  << std ::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " has no hitpoints no attack!!" << std::endl;
    }
    if (_energyPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " has no energypoints no attack!!" << std::endl;
    }
    _energyPoints--;
    std::cout << "ClapTrap " << _name << " attacks "<< target << ", causing " << _attackDamage 
        << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
        return;
    }
    if (amount >= _hitPoints)
        _hitPoints = 0;
    else
        _hitPoints -= amount;
    
    std::cout << "ClapTrap " << _name << " takes " << amount
        << " points of damage! Hit points: " << _hitPoints << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " can't repair, it has no hit points!"
            << std::endl;
        return ;
    }
    if (_energyPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " can't repair, it has no energy points!"
            << std::endl;
        return ;
    }
    _energyPoints--;
    _hitPoints += amount;
    std::cout << "ClapTrap " << _name << " repairs itself, gaining " << amount
        << " hit points! Hit Points:  " << _hitPoints << std::endl;
}