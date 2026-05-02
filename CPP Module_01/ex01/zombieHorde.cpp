/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:52:15 by gkamanur          #+#    #+#             */
/*   Updated: 2026/02/19 15:25:08 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) 
{
    // uses unnamed constructor
    if (N <= 0)
        return NULL;
    
    Zombie* horde = new Zombie[N];
    for (int i = 0; i < N; i++) 
    {
        horde[i].setName(name);
    }
    return horde;
}

Zombie* zombieHorde_named(int N, std::string name) 
{
    // uses named constructor
    if (N <= 0)
        return NULL;
    
    Zombie* horde = new Zombie[N];
    for (int i = 0; i < N; i++) 
    {
        horde[i] = Zombie(name);
    }
    return horde;
}