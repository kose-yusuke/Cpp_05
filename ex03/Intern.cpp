/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:49:09 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/11/29 16:22:25 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

Intern::Intern(){}

Intern::Intern(const Intern &other){
    *this = other;
}

Intern &Intern::operator=(const Intern &other){
    if (this == &other)
		return *this;
	return *this;
}

Intern::~Intern() {}

AForm* Intern::createShrubberyCreationForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string &form_type, const std::string &target) {
    std::string forms[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    AForm* (Intern::*forms_ptr[])(const std::string&) = {
        &Intern::createShrubberyCreationForm,
        &Intern::createRobotomyRequestForm,
        &Intern::createPresidentialPardonForm
    }; 

    for (int i=0;i < 3;i++){
        if (forms[i] == form_type){
            std::cout << "Intern creates " << form_type << std::endl;
            return (this->*forms_ptr[i])(target);
        }
    }
    std::cout << "Intern cannot create " << form_type << " because it doesn't exist." << std::endl;
    return NULL;
}
