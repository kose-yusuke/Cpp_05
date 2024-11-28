/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:18:34 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/11/29 00:04:21 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include <stdexcept>
#include "Form.hpp"

class Form;

class Bureaucrat {
    private:
        const std::string _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);

        const std::string& getName() const;
        int getGrade() const;

        void incrementGrade();
        void decrementGrade();

        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };

        void signForm(Form& form) const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);