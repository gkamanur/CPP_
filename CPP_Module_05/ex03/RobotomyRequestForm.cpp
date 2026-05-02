/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 13:17:34 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/30 17:44:58 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), _target("default")
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 25, 5), _target(target)
{
     std::cout << "Robotomy request Form " << target << " created .." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) 
    : AForm(other), _target(other._target)
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

void RobotomyRequestForm::execute(const Bureaucrat &exec) const
{
    if (!isSigned())
        throw FormNotsignedException();
    if (exec.getGrade() > getGradetoExecute())
        throw GradeTooLowException();
        
    std::cout << "* DRILLING NOISES * ";
    std::cout << "Brrrrrrrrrrrrrrrrrrrr! ";
    std::cout << "Whirrrrrrrrrrrrrrr! ";
    std::cout << "Crrrrrrrrrrrrrrrrr!" << std::endl;
    
    if (std::rand() % 2)
        std::cout << _target << " has been robotomized successfully!!!" << std::endl;
    else
        std::cout << "Robotomy Failed on " << _target << "!" << std::endl;
}