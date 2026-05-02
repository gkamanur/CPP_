/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 15:34:09 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/30 15:45:59 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Bureaucrat.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/PresidentialPardonForm.hpp"

void testShrubbery()
{
    std::cout << "++++++Create Form++++++"<< std::endl;
    Bureaucrat low("Low", 140);
    ShrubberyCreationForm form("garden");

    low.signForm(form);
    low.exec(form);
}

void testRobotomy()
{
    std::cout << std::endl << "+++++++Robotomy++++++++" << std::endl;
    
    Bureaucrat mid("Mid", 70);
    ShrubberyCreationForm form("Bender");
    
    mid.signForm(form);
    mid.exec(form);
}

void testPardon()
{
    std::cout <<std::endl << "+++++++Pardon++++++++" <<std::endl;
    
    Bureaucrat high ("High", 1);
    PresidentialPardonForm form("Ford");
    
    high.signForm(form);
    high.exec(form);
}

void testErrors()
{
    std::cout << std::endl << "++++++Errors+++++++" << std::endl;
    
    ShrubberyCreationForm form("test");
    Bureaucrat low("low", 150);

    low.signForm(form);
    try
    {
        form.execute(low);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
}

void testRobotomyLoop()
{
    std::cout << std::endl << "--------Robotomy Loop-------" << std::endl;
    
    Bureaucrat high("High", 1);
    RobotomyRequestForm form ("Robot");

    high.signForm(form);

    for(int i = 0; i < 3; i++)
    {
        std::cout << "Attempt " << i + 1 << ": ";
        high.exec(form);
    }
}

int main()
{
    std::cout << "=====Testing Bureaucrat creation=====" <<std::endl << std ::endl;
    try {
        testShrubbery();
        testRobotomy();
        testPardon();
        testErrors();
        testRobotomyLoop();
    }
    catch (const std::exception &e)
    {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }
    return (0);
}