/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 17:21:47 by gkamanur          #+#    #+#             */
/*   Updated: 2026/04/09 16:19:47 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"
#include "derived/A.hpp"
#include "derived/B.hpp"
#include "derived/C.hpp"
#include "derived/D.hpp"

void testRandomObject()
{
    std::cout << "----Test 1: Random object -----" << std::endl;
    Base* obj = generate();
    identify(obj);
    identify(*obj);
    delete obj;
}

void testKnownTypes()
{
    std::cout << "\n----Test 2:known types-----" << std::endl;
    
    A a;
    B b;
    C c;
    D d;
    identify(&a);
    identify(&b);
    identify(&c);
    identify(&d);
    
    identify(a);
    identify(b);
    identify(c);
    identify(d);
}

void testMultipleRandom()
{
    std::cout << "\n---Test 3: Multiple random objects----" << std::endl;
    


    for (int i = 0; i < 5; i++)
    {
        Base* obj = generate();
        identify(obj);
        identify(*obj);
        delete obj;
    }
}

void testNullPointer()
{
    std::cout << "\n----Test 4: Null pointer---" << std::endl;
    
    Base* nullPtr = NULL;
    identify(nullPtr);
}

int main()
{
    std::cout << "=== SIMPLE TESTS ===\n" << std::endl;

    testRandomObject();
    testKnownTypes();
    testMultipleRandom();
    testNullPointer();

    std::cout << "\n=== END ===" << std::endl;
    return 0;
}
