/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 15:34:09 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/30 17:53:21 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Bureaucrat.hpp"
#include "includes/ShrubberyCreationForm.hpp"
#include "includes/RobotomyRequestForm.hpp"
#include "includes/PresidentialPardonForm.hpp"
#include "includes/Intern.hpp"
#include "includes/AForm.hpp"

void processForm(AForm* form, Bureaucrat &boss)
{
    if (!form)
        return ;
    std::cout << *form << std::endl;
    boss.signForm(*form);
    boss.exec(*form);
    delete form;
}

void testBasicIntern()
{
    std::cout << std::endl << "+++++Basic Intern Test++++++" << std::endl;
    
    Intern intern;
    Bureaucrat boss("Boss", 1);
    
    processForm(intern.makeForm("Shrubbery creation", "office"), boss);
    processForm(intern.makeForm("Robotomy creation", "Marvin"), boss);
    processForm(intern.makeForm("Presidential pardon", "Arthur"), boss);
    
    std::cout << "===Invalid Form Test===" << std::endl;
    AForm* invalid = intern.makeForm("Invalid", "target");
    delete invalid;
}

void testDifferentBureaucrats()
{
    std::cout << std::endl << "-------Different Bureaucrats------" << std::endl;

    Intern intern;
    Bureaucrat low("Low", 100);
    Bureaucrat mid("Mid", 50);
    Bureaucrat high("High", 1);

    AForm* shrub = intern.makeForm("Shrubbery creation", "park");
    AForm* robot = intern.makeForm("Robotomy request", "Robort");

    if(shrub)
    {
        std::cout << std::endl << "==Low tries: ==" << std::endl;
        low.signForm(*shrub);
        low.exec(*shrub);
        delete shrub;
    }
    if(robot)
    {
        std::cout << std::endl << "==Mid tries : ==" << std::endl;
        mid.signForm(*robot);
        mid.exec(*robot);

        std::cout << std::endl << "==High Tries : ==" << std::endl;
        high.signForm(*robot);
        high.exec(*robot);
        delete robot;
    }
    
}

int main()
{
    std::cout << "=====Testing Bureaucrat creation=====" <<std::endl << std ::endl;
    try {
        testBasicIntern();
        testDifferentBureaucrats();
    }
    catch (const std::exception &e)
    {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }
    return (0);
}