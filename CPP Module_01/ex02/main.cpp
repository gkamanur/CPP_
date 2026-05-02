/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 15:44:07 by gkamanur          #+#    #+#             */
/*   Updated: 2026/02/19 15:45:01 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;
    
    std::cout << "========== MEMORY ADDRESSES ==========" << std::endl;
    std::cout << "Address of str:       " << &str << std::endl;
    std::cout << "Address in stringPTR: " << stringPTR << std::endl;
    std::cout << "Address of stringREF: " << &stringREF << std::endl;
    
    std::cout << "\n(Notice: All three addresses are the SAME!)" << std::endl;
    std::cout << "(They all point to the same location in memory)" << std::endl;
    
    std::cout << "\n========== VALUES ==========" << std::endl;
    std::cout << "Value of str:       " << str << std::endl;
    std::cout << "Value of *stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value of stringREF: " << stringREF << std::endl;
    
    std::cout << "\n(Notice: All three values are the SAME!)" << std::endl;
    std::cout << "(Because they all access the same string)" << std::endl;
    
    /*
    ** KEY DIFFERENCES DEMONSTRATION
    */
    std::cout << "\n========== KEY DIFFERENCES ==========" << std::endl;
    
    // Changing through reference changes the original
    std::cout << "\nChanging stringREF to 'CHANGED!'..." << std::endl;
    stringREF = "CHANGED!";
    std::cout << "str is now: " << str << std::endl;
    std::cout << "(Reference changed the original!)" << std::endl;
    
    // Changing through pointer also changes the original
    std::cout << "\nChanging *stringPTR to 'CHANGED AGAIN!'..." << std::endl;
    *stringPTR = "CHANGED AGAIN!";
    std::cout << "str is now: " << str << std::endl;
    std::cout << "(Pointer also changed the original!)" << std::endl;
    
    return 0;
}

/*
** SUMMARY:
** 
** ┌───────────────────────────────────────────────────────────────────┐
** │                                                                   │
** │  POINTER                        REFERENCE                         │
** │  ───────                        ─────────                         │
** │  std::string* ptr = &str;       std::string& ref = str;           │
** │                                                                   │
** │  ptr  = address of str          ref = IS str (alias)              │
** │  *ptr = value at address        ref = value (no * needed)         │
** │                                                                   │
** │  Can be NULL                    CANNOT be NULL                    │
** │  Can change target              CANNOT change target              │
** │  Must use * to get value        Automatically gets value          │
** │                                                                   │
** └───────────────────────────────────────────────────────────────────┘
*/
