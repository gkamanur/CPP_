/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkamanur <gkamanur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 10:30:38 by gkamanur          #+#    #+#             */
/*   Updated: 2026/03/30 12:33:10 by gkamanur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
# include "Bureaucrat.hpp"

class Bureaucrat ;
class Form
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradetoExecute;
        const int _gradetoSign;
    public:
        Form();
        Form(const std::string &name, int gradetoSign, int gradetoExecute);
        Form(const Form &other);
        Form &operator=(const Form &rhs);
        ~Form();
        
        const std::string &getName() const;
        bool isSigned() const;
        int getGradetoSign() const;
        int getGradetoExecute() const;
        
        void beSigned(const Bureaucrat &bureaucrat);
        
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

        
};
std::ostream &operator<< (std::ostream &os, const Form &form);
# endif