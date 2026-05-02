/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:20:46 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/31 20:54:19 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include "utils.hpp"
#include <iostream>

int main(void)
{
    Phonebook phonebook;
    std::string cmd;
    
    while(1)
    {
        Utils::println ("<<< Enter Command : [ADD(a), SEARCH(s), EXIT(exit)] >>>");
        std::getline(std::cin, cmd);
        
        if(std::cin.eof())
        {
            Utils::println("EEROR : error please check here!!");
            break ;
        }
        if ((cmd == "a") || (cmd == "ADD"))
        {
            std::cout << "====================================================================" << std::endl << std::endl;
            phonebook.validate_addcontact();
        }
        else if (cmd == "s")
        {
            phonebook.searchcontact();
        }
        else if (cmd == "exit")
            break;
        else
            Utils::println("ERROR : Put proper command or press ctrl+c");
    }
    return (0);
}
