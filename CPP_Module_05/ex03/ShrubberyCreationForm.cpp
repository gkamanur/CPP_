/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 15:18:11 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/30 15:33:34 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) 
    : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) 
    : AForm(other), _target(other._target)
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void ShrubberyCreationForm::execute(const Bureaucrat &exec) const
{
    if (!isSigned())
        throw FormNotsignedException();
    if (exec.getGrade() > getGradetoExecute())
        throw GradeTooLowException();
    
    std::string filename = _target + "_Shrubbery";
    std::ofstream file (filename.c_str());
    if (file.is_open())
    {
        file << "    /\\    " << std::endl;
        file << "   /  \\   " << std::endl;
        file << "  /    \\  " << std::endl;
        file << " /      \\ " << std::endl;
        file << "/________\\" << std::endl;
        file << "    ||    " << std::endl;
        file << "    ||    " << std::endl;
        file.close();
        std::cout << "Shrubbery created at " << _target << "_shrubbery" << std::endl;
    }
    else
    {
        std::cout << "Error: Could not create shrubbery file" << std::endl;
    }
}