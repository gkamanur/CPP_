/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 10:42:28 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/30 11:32:43 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"

Form::Form() : _name("Default"), _isSigned(false), _gradetoExecute(150), _gradetoSign(150)
{}

Form::Form(const std::string &name, int gts, int gte)
    : _name(name), _isSigned(false), _gradetoExecute(gte), _gradetoSign(gts)
{
    if (gts < 1 || gte < 1)
        throw GradeTooHighException();
    if (gts > 150 || gte > 150)
        throw GradeTooLowException();
}

Form::Form (const Form &other) : _name(other._name), _isSigned(other._isSigned),
    _gradetoExecute(other._gradetoExecute), _gradetoSign(other._gradetoSign)
{}
    
Form &Form::operator=(const Form &rhs)
{
    if (this != &rhs)
        _isSigned = rhs._isSigned;
    return (*this);
}

Form::~Form(){}

const std::string &Form::getName() const
{
    return (_name);
}

bool Form::isSigned() const
{
    return (_isSigned);
}

int Form::getGradetoSign() const
{
    return (_gradetoSign);
}

int Form::getGradetoExecute() const
{
    return (_gradetoExecute);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= _gradetoSign)
        _isSigned = true;
    else
        throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form grade is too high! Maximum grade is 1";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form grade is too low! Minimum grade is 150";
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << "Form: " << form.getName()
       <<   "| Signed: " << (form.isSigned() ? "Yes" : "No")
       <<   "| Grade to sign: " << form.getGradetoSign()
       <<   "| Grade to execute: " << form.getGradetoExecute();
    return os;
}
