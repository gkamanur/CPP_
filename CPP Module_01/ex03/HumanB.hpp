/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:26:10 by gkamanur          #+#    #+#             */
/*   Updated: 2026/02/23 15:49:56 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
private:
    std::string _name;
    Weapon* _weapon;  // POINTER - can be NULL, can be set later

public:
    HumanB(std::string name);
    ~HumanB(void);

    void setWeapon(Weapon& weapon);
    
    void attack(void) const;
};

#endif
