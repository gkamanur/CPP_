/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 15:34:09 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/30 10:27:01 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

void testValid()
{
    std::cout << "\n--------- creation---------\n";
    Bureaucrat a("John", 25);
    Bureaucrat b("High", 1);
    Bureaucrat c("Low", 150);
    
    std::cout << a << std::endl << b << std::endl << c <<std::endl;
}

void testInvalid()
{
    std::cout << "\n---------Invalid grades---------\n";
    try {
        Bureaucrat ("TooHigh", 0);
    }
    catch(const std::exception& e) {
        std::cout << e.what() << '\n';
    }
    try {
        Bureaucrat ("TooLow", 151);
    }
    catch(const std::exception& e) {
        std::cout << e.what() << '\n';
    }
    
}

void testIncrement()
{
    std::cout << std::endl << "======Increment Test======" << std::endl;
    
    Bureaucrat bob("Bob", 2);
    std::cout << bob << std::endl;
    
    bob.incrementGrade();
    std::cout << bob << std::endl;

    try{
        bob.incrementGrade();
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

void testDecrement()
{
    std::cout << std::endl << "======Increment Test======" << std::endl;
    
    Bureaucrat alice("Alice", 149);
    std::cout << alice << std::endl;
    
    alice.decrementGrade();
    std::cout << alice << std::endl;

    try{
        alice.decrementGrade();
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

int main()
{
    std::cout << "=====Testing Bureaucrat creation=====" <<std::endl << std ::endl;
    try {
        testValid();
        testInvalid();
        testIncrement();
        testDecrement();
    }
    catch (const std::exception &e)
    {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }
    return (0);
}