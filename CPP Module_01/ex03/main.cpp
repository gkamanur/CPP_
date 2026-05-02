/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:26:41 by gkamanur          #+#    #+#             */
/*   Updated: 2026/02/23 16:22:27 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{

    {
        std::cout << "========== HumanA (REFERENCE) ==========" << std::endl;
        
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();

        club.setType("some other type of club");
        bob.attack();
        
        std::cout << std::endl;
    }
    
    {
        std::cout << "========== HumanB (POINTER) ==========" << std::endl;
        
        Weapon club = Weapon("crude spiked club");
        
        // Jim is created WITHOUT a weapon - possible because he uses pointer
        HumanB jim("Jim");
        
        // Give Jim a weapon later
        jim.setWeapon(club);
        jim.attack();
        
        // Change the weapon type
        club.setType("some other type of club");
        jim.attack();
        
        std::cout << std::endl;
    }
    
    return 0;
}

/*
** EXPECTED OUTPUT:
**
** ========== HumanA (REFERENCE) ==========
** Bob attacks with their crude spiked club
** Bob attacks with their some other type of club
**
** ========== HumanB (POINTER) ==========
** Jim attacks with their crude spiked club
** Jim attacks with their some other type of club
**
**
** KEY TAKEAWAY:
** ═══════════════════════════════════════════════════════════════════════
**
** Both Bob and Jim see the weapon change because:
** - Bob's reference IS the club
** - Jim's pointer POINTS TO the club
**
** In both cases, they're accessing the SAME original weapon object!
**
** The DIFFERENCE is in construction:
** - Bob MUST have a weapon at birth (reference)
** - Jim CAN start weaponless and get one later (pointer)
**
** ═══════════════════════════════════════════════════════════════════════
*/
