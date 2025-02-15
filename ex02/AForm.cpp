/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:22:57 by koseki.yusu       #+#    #+#             */
/*   Updated: 2025/02/16 06:44:24 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _is_signed(false), _grade_to_sign(150), _grade_to_execute(150){}

AForm::AForm(const std::string& name, int grade_to_sign, int grade_to_execute) : _name(name), _is_signed(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute){}

AForm::~AForm(){}

AForm::AForm(const AForm &other) : _name(other._name), _is_signed(other._is_signed), _grade_to_sign(other._grade_to_sign), _grade_to_execute(other._grade_to_execute) {}

AForm &AForm::operator=(const AForm &other) {
    if (this != &other) {
        _is_signed = other._is_signed;
    }
    return *this;
}

const std::string& AForm::getName() const {
    return _name;
}

bool AForm::isSigned() const {
    return _is_signed;
}

int AForm::getGradeToSign() const {
    return _grade_to_sign;
}

int AForm::getGradeToExecute() const {
    return _grade_to_execute;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= _grade_to_sign) {
        _is_signed = true;
    } else {
        throw GradeTooLowException();
    }
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "Form " << form.getName() << " is " << (form.isSigned() ? "signed" : "not signed");
    return os;
}