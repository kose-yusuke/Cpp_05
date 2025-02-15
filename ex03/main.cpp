/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:26:16 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/11/29 16:32:18 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <cstdlib>

int main() {
    srand((int)time(NULL));
	std::cout << "Test start!!" << std::endl;
    Intern intern;
    Bureaucrat bureaucrat("Donald Trump", 1);
    std::cout << "=============Trial1===========" << std::endl;
    try {
        AForm* form = intern.makeForm("ShrubberyCreationForm", "home");
        if (form) {
            bureaucrat.signForm(*form);
            bureaucrat.executeForm(*form);
            delete form;
        }
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
    std::cout << "=============Trial2===========" << std::endl;
    try {
        AForm* form = intern.makeForm("RobotomyRequestForm", "Bender");
        if (form) {
            bureaucrat.signForm(*form);
            bureaucrat.executeForm(*form);
            delete form;
        }
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
    std::cout << "=============Trial3===========" << std::endl;
    try {
        AForm* form = intern.makeForm("PresidentialPardonForm", "Marvin");
        if (form) {
            bureaucrat.signForm(*form);
            bureaucrat.executeForm(*form);
            delete form;
        }
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
    std::cout << "=============UnknownForm===========" << std::endl;
    try {
        AForm* form = intern.makeForm("UnknownForm", "Unknown");
        if (form) {
            bureaucrat.signForm(*form);
            bureaucrat.executeForm(*form);
            delete form;
        }
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
    std::cout << "Fin" << std::endl;
    return 0;
}

