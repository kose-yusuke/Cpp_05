/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 22:20:51 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/11/29 00:04:28 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
    private:
        const std::string name_;
        bool is_signed_;
        const int grade_for_sign_;
        const int grade_for_execute_;
    public:
        Form();
        Form(const std::string& name, int grade_for_sign, int grade_for_execute);
        ~Form();
        Form(const Form &other);
        Form &operator=(const Form &other);
        
        const std::string& getName() const;
        bool isSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        class GradeTooHighException : public std::exception {
        public:
            const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
        public:
            const char* what() const throw();
        };
        
        void beSigned(const Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& os, const Form& form);