/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 18:19:23 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/19 16:27:49 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

int main()
{
    std::cout << "------Create ClapTrap--------" << std::endl;
    ClapTrap a("Alpha");
    ScavTrap b("Beta");
    FragTrap c("Gamma");

    std::cout << std::endl << "-------Attack tests-------" << std::endl;
    a.attack("Beta");
    b.attack("Gamma");
    c.attack("Alpha");
    
    std::cout << std::endl << "--------Special Abilities------------" << std::endl;
    b.guardgate();
    c.highFivesGuys();
    
    std::cout << std::endl << "-------Damage and Repair Test--------" << std::endl;
    c.beRepaired(50);
    c.takeDamage(30);   

    std::cout << std::endl << "======Destruction========" << std::endl;
    return (0);
    
}