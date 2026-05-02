/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 18:19:23 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/17 07:06:02 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScavTrap.hpp"

int main()
{
    std::cout << "------Create ClapTrap--------" << std::endl;
    ClapTrap a("Alpha");
    ScavTrap b("Beta");

    std::cout << std::endl << "-------Attack tests-------" << std::endl;
    a.attack("Beta");
    b.attack("Alpha");

    std::cout << std::endl << "-------Damage and Repair Test--------" << std::endl;
    b.beRepaired(10);
    b.takeDamage(30);

    std::cout << std::endl << "-----Special------" << std::endl;
    b.guardgate();
   

    std::cout << std::endl << "======Destruction========" << std::endl;
    return (0);
    
}