/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:49:21 by gkamanur          #+#    #+#             */
/*   Updated: 2026/02/19 15:25:14 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) 
{
    int hordeSize = 5;
    
    std::cout << "\n========== CREATING ZOMBIE HORDE ==========" << std::endl;
    std::cout << "Creating a horde of " << hordeSize << " zombies..." << std::endl;
    std::cout << std::endl;
    
    Zombie* horde = zombieHorde(hordeSize, "Walker");
    // Zombie* horde = zombieHorde_named(hordeSize, "Walker");

    
    std::cout << "\n========== HORDE ANNOUNCES ==========" << std::endl;
    
    for (int i = 0; i < hordeSize; i++)
    {
        std::cout << "Zombie #" << i << ": ";
        horde[i].announce();
    }
    
    std::cout << "\n========== DELETING HORDE ==========" << std::endl;
    std::cout << "Using delete[] to free all " << hordeSize << " zombies..." << std::endl;
    std::cout << std::endl;
    
    delete[] horde;
    
    std::cout << "\n========== TEST COMPLETE ==========" << std::endl;
    return 0;
}

/*
** EXPECTED OUTPUT:
**
** ========== CREATING ZOMBIE HORDE ==========
** Creating a horde of 5 zombies...
**
** ========== HORDE ANNOUNCES ==========
** Zombie #0: Walker: BraiiiiiiinnnzzzZ...
** Zombie #1: Walker: BraiiiiiiinnnzzzZ...
** Zombie #2: Walker: BraiiiiiiinnnzzzZ...
** Zombie #3: Walker: BraiiiiiiinnnzzzZ...
** Zombie #4: Walker: BraiiiiiiinnnzzzZ...
**
** ========== DELETING HORDE ==========
** Using delete[] to free all 5 zombies...
**
** Walker is destroyed!
** Walker is destroyed!
** Walker is destroyed!
** Walker is destroyed!
** Walker is destroyed!
**
** ========== TEST COMPLETE ==========
*/
