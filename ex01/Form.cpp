/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 23:32:16 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/11/29 11:22:22 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : name_(""), is_signed_(false), grade_to_sign_(1), grade_to_execute_(1) {
    if (grade_to_sign_ < 1)
        throw GradeTooHighException();
    else if (grade_to_sign_ > 150)
        throw GradeTooLowException();
    if (grade_to_execute_ < 1)
        throw GradeTooHighException();
    else if (grade_to_execute_ > 150)
        throw GradeTooLowException();
}

Form::Form(const std::string& name, int grade_to_sign, int grade_to_execute) : name_(name), is_signed_(false), grade_to_sign_(grade_to_sign), grade_to_execute_(grade_to_execute) {
    if (grade_to_sign_ < 1)
        throw GradeTooHighException();
    else if (grade_to_sign_ > 150)
        throw GradeTooLowException();
    if (grade_to_execute_ < 1)
        throw GradeTooHighException();
    else if (grade_to_execute_ > 150)
        throw GradeTooLowException();
}

Form::~Form() {}

Form::Form(const Form &other) : name_(other.name_), is_signed_(other.is_signed_), grade_to_sign_(other.grade_to_sign_), grade_to_execute_(other.grade_to_execute_) {}

Form &Form::operator=(const Form &other) {
    if (this != &other) {
        is_signed_ = other.is_signed_;
    }
    return *this;
}

const std::string& Form::getName() const {
    return name_;
}

bool Form::isSigned() const {
    return is_signed_;
}

int Form::getGradeToSign() const {
    return grade_to_sign_;
}

int Form::getGradeToExecute() const {
    return grade_to_execute_;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() <= grade_to_sign_) {
        is_signed_ = true;
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