/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by permanent u       #+#    #+#             */
/*   Updated: 2026/02/17 18:21:12 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie 
{
private:
    std::string _name;  // The zombie's name (hidden from outside)

public:
    Zombie(std::string name);
    ~Zombie(void);
    void announce(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);


#endif
