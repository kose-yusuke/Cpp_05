/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:22:57 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/11/29 13:26:10 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name_("default"), is_signed_(false), grade_to_sign_(150), grade_to_execute_(150){}

AForm::AForm(const std::string& name, int grade_to_sign, int grade_to_execute) : name_(name), is_signed_(false), grade_to_sign_(grade_to_sign), grade_to_execute_(grade_to_execute){}

AForm::~AForm(){}

AForm::AForm(const AForm &other) : name_(other.name_), is_signed_(other.is_signed_), grade_to_sign_(other.grade_to_sign_), grade_to_execute_(other.grade_to_execute_) {}

AForm &AForm::operator=(const AForm &other) {
    if (this != &other) {
        is_signed_ = other.is_signed_;
    }
    return *this;
}

const std::string& AForm::getName() const {
    return name_;
}

bool AForm::isSigned() const {
    return is_signed_;
}

int AForm::getGradeToSign() const {
    return grade_to_sign_;
}

int AForm::getGradeToExecute() const {
    return grade_to_execute_;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= grade_to_sign_) {
        is_signed_ = true;
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