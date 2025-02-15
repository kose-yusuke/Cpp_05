/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 23:32:16 by koseki.yusu       #+#    #+#             */
/*   Updated: 2025/02/16 06:41:26 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : _name(""), _is_signed(false), _grade_to_sign(1), _grade_to_execute(1) {
    if (_grade_to_sign < 1)
        throw GradeTooHighException();
    else if (_grade_to_sign > 150)
        throw GradeTooLowException();
    if (_grade_to_execute < 1)
        throw GradeTooHighException();
    else if (_grade_to_execute > 150)
        throw GradeTooLowException();
}

Form::Form(const std::string& name, int grade_to_sign, int grade_to_execute) : _name(name), _is_signed(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute) {
    if (_grade_to_sign < 1)
        throw GradeTooHighException();
    else if (_grade_to_sign > 150)
        throw GradeTooLowException();
    if (_grade_to_execute < 1)
        throw GradeTooHighException();
    else if (_grade_to_execute > 150)
        throw GradeTooLowException();
}

Form::~Form() {}

Form::Form(const Form &other) : _name(other._name), _is_signed(other._is_signed), _grade_to_sign(other._grade_to_sign), _grade_to_execute(other._grade_to_execute) {}

Form &Form::operator=(const Form &other) {
    if (this != &other) {
        _is_signed = other._is_signed;
    }
    return *this;
}

const std::string& Form::getName() const {
    return _name;
}

bool Form::isSigned() const {
    return _is_signed;
}

int Form::getGradeToSign() const {
    return _grade_to_sign;
}

int Form::getGradeToExecute() const {
    return _grade_to_execute;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= _grade_to_sign) {
        _is_signed = true;
    } else {
        throw GradeTooLowException();
    }
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form " << form.getName() << " is " << (form.isSigned() ? "signed" : "not signed");
    return os;
}