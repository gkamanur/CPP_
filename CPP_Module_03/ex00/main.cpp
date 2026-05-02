/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 18:19:23 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/16 18:29:24 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

int main()
{
    std::cout << "------Create ClapTrap--------" << std::endl;
    ClapTrap a("Alpha");
    ClapTrap b("Beta");

    std::cout << std::endl << "-------Attack tests-------" << std::endl;
    a.attack("Beta");
    b.takeDamage(0);

    std::cout << std::endl << "-------Repair Test--------" << std::endl;
    b.beRepaired(5);

    std::cout << std::endl << "------Heavy damage test-------" << std::endl;
    b.takeDamage(20);
    b.attack("Alpha");
    b.beRepaired(5);

    std::cout << std::endl << "-------Energy Drain Test---------" << std::endl;
    for (int i = 0; i < 11; i++)
        a.attack("Beta");

    std::cout << std::endl << "-------Copy Test--------" << std::endl;
    ClapTrap c(a);

    std::cout << std::endl << "======Destruction========" << std::endl;

    return (0);
    
}