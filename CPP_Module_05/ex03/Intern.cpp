/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 15:51:39 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/31 09:23:14 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/Intern.hpp"

Intern::Intern(){}

Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return *this;
}

Intern::~Intern(){}

AForm* Intern::makeShrubbery(const std::string& t) 
{ 
    return new ShrubberyCreationForm(t);
}

AForm* Intern::makeRobotomy (const std::string& t) 
{
    return new RobotomyRequestForm(t);
}

AForm* Intern::makePardon   (const std::string& t)
{ 
    return new PresidentialPardonForm(t);
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target)
{
   typedef AForm* (Intern::*FormCreator)(const std::string&);
    
    std::string formTypes[3] = {
        "Shrubbery creation",
        "Robotomy creation",
        "Presidential pardon"
    };
    
    FormCreator   creators[3] = {
        &Intern::makeShrubbery,
        &Intern::makeRobotomy,
        &Intern::makePardon
    };
    
    for (int i = 0; i < 3; i++)
    {
        if (formName == formTypes[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*creators[i])(target);
        }
    }
    std::cout << "Error: Unknown form name '" << formName << "'" << std::endl;
    return NULL;
}
