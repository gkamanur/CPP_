/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 20:10:43 by gkamanur          #+#    #+#             */
/*   Updated: 2026/02/23 20:10:47 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
    Harl harl;
    
    std::cout << "========== TESTING HARL ==========" << std::endl << std::endl;
    
    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");
    
    std::cout << "========== TESTING INVALID LEVEL ==========" << std::endl << std::endl;
    harl.complain("UNKNOWN");
    
    return 0;
}
