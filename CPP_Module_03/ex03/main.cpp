/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 18:19:23 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/23 09:42:13 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "DiamondTrap.hpp"

int main()
{
    std::cout << "------DiamondTrap Construction------------" << std::endl;
    DiamondTrap d("Diamond");
    
    std::cout << std::endl << "----Whoami-----" << std::endl;
    d.whoAmi();

    std::cout << std::endl << "-------Attack(ScavTrap::attack is used)-------" << std::endl;
    d.attack("Target");

    std::cout << std::endl << "------Inherited abilities-------" << std::endl;
    d.guardgate();
    d.highFivesGuys();
    
    std::cout << std::endl << "-------Damage and Repair--------" << std::endl;
    d.takeDamage(40);
    d.beRepaired(20);
    
    std::cout << std::endl << "------Copy Test-------" << std::endl;
    DiamondTrap d2(d);
    d2.whoAmi();

    std::cout << std::endl << "---------Default values demo---------" << std ::endl;
    DiamondTrap d3;
    d3.whoAmi();
    
    std::cout << std::endl << "--------Destruction starts-------" << std::endl;
    
    return (0);
    
}