/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 15:51:11 by gkamanur          #+#    #+#             */
/*   Updated: 2026/02/19 15:25:25 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie 
{
private:
    std::string _name;

public:
    Zombie(void);
    Zombie(std::string name);
    ~Zombie(void);
    void setName(std::string name);
    void announce(void);
};

Zombie* zombieHorde(int N, std::string name);
Zombie* zombieHorde_named(int N, std::string name);

#endif
