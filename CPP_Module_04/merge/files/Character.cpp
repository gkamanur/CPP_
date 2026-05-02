/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 13:48:53 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/24 15:27:38 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Character.hpp"

Character::Character() : _name("unnamed"), _floorCount(0)
{
    for (int i = 0; i < 4; i++)
        _inventory[i] = 0;
    for (int i = 0; i < 100; i++)
        _floor[i] = 0;
}

Character::Character(std::string const &name) : _name(name), _floorCount(0)
{
    for (int i = 0; i < 4; i++)
        _inventory[i] = 0;
    for (int i = 0; i < 100; i++)
        _floor[i] = 0;
}

Character::Character(const Character &src) : _name(src._name), _floorCount(0)
{
    for (int i = 0; i < 4; i++)
    {
        if (src._inventory[i])
            _inventory[i] = src._inventory[i]->clone();
        else
            _inventory[i] = 0;
    }
    for (int i = 0; i < 100; i++)
        _floor[i] = 0;
}

Character &Character::operator=(const Character &rhs)
{
    if (this != &rhs)
    {
        _name = rhs._name;
        for(int i = 0; i < 4; i++)
        {
            delete _inventory[i];
            if (rhs._inventory[i])
                _inventory[i] = rhs._inventory[i]->clone();
            else
                _inventory[i] = 0;
            
        }
    }
    return (*this);
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
        delete _inventory[i];
    for (int i = 0; i < _floorCount; i++)
        delete _floor[i];
}

std::string const &Character::getName() const
{
    return _name;
}

void Character::equip(Amateria *m)
{
    if (!m)
        return ;
    for (int i = 0; i < 4; i++)
    {
        if (!_inventory[i])
        {
            _inventory[i] = m;
            return ;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4 || !_inventory[idx])
        return ;
    if (_floorCount < 100)
    {
        _floor[_floorCount] = _inventory[idx];
        _floorCount++;
    }
    _inventory[idx] = 0;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx >= 4 || !_inventory[idx])
        return ;
    _inventory[idx]->use(target);
}
