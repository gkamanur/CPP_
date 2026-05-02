/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 10:30:38 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/30 16:57:00 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP
# include "Bureaucrat.hpp"

class Bureaucrat ;

class AForm
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradetoExecute;
        const int _gradetoSign;
    public:
        AForm();
        AForm(const std::string &name, int gradetoSign, int gradetoExecute);
        AForm(const AForm &other);
        AForm &operator=(const AForm &rhs);
        virtual ~AForm();
        
        const std::string &getName() const;
        bool isSigned() const;
        int getGradetoSign() const;
        int getGradetoExecute() const;
        
        void beSigned(const Bureaucrat &bureaucrat);
        virtual void execute(const Bureaucrat &exec) const = 0;
        
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        
        class FormNotsignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        
};
std::ostream &operator<< (std::ostream &os, const AForm &form);
# endif