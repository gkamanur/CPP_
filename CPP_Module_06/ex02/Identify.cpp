/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 16:26:47 by gkamanur          #+#    #+#             */
/*   Updated: 2026/04/09 16:23:57 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"
#include "derived/A.hpp"
#include "derived/B.hpp"
#include "derived/C.hpp"
#include <cstdlib>
#include <ctime>
#include <typeinfo>

Base* generate(void)
{
    static bool seeded = false;
    if(!seeded)
    {
        std::srand(static_cast<unsigned int>(std::time(NULL)));
        seeded = true;
    }
    int random = std::rand() % 3;
    
    switch (random)
    {
        case 0:
            std::cout << "Generated: A" << std::endl;
            return new A();
        case 1:
            std::cout << "Generated: B" << std::endl;
            return new B();
        case 2:
            std::cout << "Generated: C" << std::endl;
            return new C();
        default:
            return NULL;
            
    }
}

void identify(Base* p)
{
    if (!p)
    {
        std::cout << "NULL Pointer" << std::endl;
        return;
    }
    if (dynamic_cast<A*>(p))
        std::cout << "*A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "*B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "*C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
    // For references, dynamic_cast throws std::bad_cast on failure
    // So we need to catch exceptions
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "&A" << std::endl;
        return;
    }
    catch (std::bad_cast&) {}
    
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "&B" << std::endl;
        return;
    }
    catch (std::bad_cast&) {}
    
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "&C" << std::endl;
        return;
    }
    catch (std::bad_cast&) {}
    
    std::cout << "Unknown type" << std::endl;
}