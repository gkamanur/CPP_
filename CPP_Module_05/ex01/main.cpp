/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 15:34:09 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/30 12:14:18 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

void testForm()
{
    std::cout << "++++++Create Form++++++"<< std::endl;
    Form taxForm("Tax Forn", 50, 30);
    std::cout << taxForm << std::endl;
}

void testInvalidForm()
{
    std::cout << std::endl << "+++++++Invalid Forms+++++++" << std::endl;
    try
    {
        Form("High Form", 0, 50);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Form("Low Form", 151, 50);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void testSign()
{
    std::cout << std::endl << "+++++++Form Signing++++++" << std::endl;
    
    Bureaucrat guru("Guru", 75);
    Bureaucrat milan("Milan", 40);
    Form form("Important Form", 50, 50);
    
    std::cout << form << std::endl;
    
    std::cout << std::endl << "Guru tries: ";
    guru.signForm(form);
    
    std::cout << "Milan tries: ";
    milan.signForm(form);
    
    std::cout << std::endl << "Result  ";
    std::cout << form << std::endl;
    
}

void testMultipleForms()
{
    std::cout << "+++++++Multiple forms+++++++";
    
    Form easy("Form Easy", 100, 90);
    Form hard("Hard Form", 20, 15);
    Bureaucrat Romel("Romel", 30);

    Romel.signForm(easy);
    Romel.signForm(hard);

    std::cout << easy << std::endl;
    std::cout << hard <<std::endl;
}

int main()
{
    std::cout << "=====Testing Bureaucrat creation=====" <<std::endl << std ::endl;
    try {
        testForm();
        testInvalidForm();
        testSign();
        testMultipleForms();
    }
    catch (const std::exception &e)
    {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }
    return (0);
}