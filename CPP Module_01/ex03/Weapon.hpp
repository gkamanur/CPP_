/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:04:13 by gkamanur          #+#    #+#             */
/*   Updated: 2026/02/23 16:20:24 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon {
private:
    std::string _type;

public:
    // Constructor: Create a weapon with a type
    Weapon(std::string type);

    ~Weapon(void);
    
    const std::string& getType(void) const;
    void setType(std::string type);
};

#endif
