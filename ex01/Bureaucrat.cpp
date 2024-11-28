/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:42:50 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/11/29 00:02:29 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade){
    if (_grade < 1)
        throw GradeTooHighException();
    else if (_grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat(){}

const std::string& Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::incrementGrade(){
    if (_grade - 1 < 1)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade(){
    if (_grade + 1 > 150)
        throw GradeTooLowException();
    _grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat){
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}

void Bureaucrat::signForm(Form& form) const{
    try {
        form.beSigned(*this);
        std::cout << getName() << " signed " << form.getName() << std::endl;   
    } catch (const std::exception& e){
        std::cout << getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}
