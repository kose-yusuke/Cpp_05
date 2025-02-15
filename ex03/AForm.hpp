/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:14:42 by koseki.yusu       #+#    #+#             */
/*   Updated: 2025/02/16 06:47:01 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>
#include <string>
#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm{
    public:
        AForm();
        AForm(const std::string& name, int grade_to_sign, int grade_to_execute);
        virtual ~AForm();
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        const std::string& getName() const;
        bool isSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        void beSigned(const Bureaucrat& bureaucrat);
        
        virtual void execute(Bureaucrat const& executor) const = 0;
        
        class GradeTooHighException : public std::exception {
        public:
            const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
        public:
            const char* what() const throw();
        };

        class FormNotSignedException : public std::exception {
        public:
            const char* what() const throw();
        };

    private:
        const std::string _name;
        bool _is_signed;
        const int _grade_to_sign;
        const int _grade_to_execute;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);