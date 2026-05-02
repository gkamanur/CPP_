/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 19:05:59 by gkamanur          #+#    #+#             */
/*   Updated: 2026/04/27 19:28:00 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"

#include <iostream>
#include <exception>

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error " << std::endl;
        return 1;
    }

    try
    {
        RPN rpn;
        int result = rpn.evaluate(av[1]);
        std::cout << result << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    return 0;
}