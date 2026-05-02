/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 10:42:28 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/30 11:32:43 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/AForm.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _gradetoExecute(150), _gradetoSign(150)
{}

AForm::AForm(const std::string &name, int gts, int gte)
    : _name(name), _isSigned(false), _gradetoExecute(gte), _gradetoSign(gts)
{
    if (gts < 1 || gte < 1)
        throw GradeTooHighException();
    if (gts > 150 || gte > 150)
        throw GradeTooLowException();
}

AForm::AForm (const AForm &other) : _name(other._name), _isSigned(other._isSigned),
    _gradetoExecute(other._gradetoExecute), _gradetoSign(other._gradetoSign)
{}
    
AForm &AForm::operator=(const AForm &rhs)
{
    if (this != &rhs)
        _isSigned = rhs._isSigned;
    return (*this);
}

AForm::~AForm(){}

const std::string &AForm::getName() const
{
    return (_name);
}

bool AForm::isSigned() const
{
    return (_isSigned);
}

int AForm::getGradetoSign() const
{
    return (_gradetoSign);
}

int AForm::getGradetoExecute() const
{
    return (_gradetoExecute);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= _gradetoSign)
        _isSigned = true;
    else
        throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Form grade is too high! Maximum grade is 1";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Form grade is too low! Minimum grade is 150";
}

const char* AForm::FormNotsignedException::what() const throw()
{
    return "Form is not signed";
}
std::ostream &operator<<(std::ostream &os, const AForm &AForm)
{
    os << "AForm: " << AForm.getName()
       <<   "| Signed: " << (AForm.isSigned() ? "Yes" : "No")
       <<   "| Grade to sign: " << AForm.getGradetoSign()
       <<   "| Grade to execute: " << AForm.getGradetoExecute();
    return os;
}
