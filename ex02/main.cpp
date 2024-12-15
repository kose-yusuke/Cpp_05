/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:26:16 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/12/15 15:34:23 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {

	srand((int)time(NULL));
	
    try {
		std::cout << "Test start!!" << std::endl;
        Bureaucrat bureaucrat("President", 1);
        ShrubberyCreationForm shrubbery("Home");
        RobotomyRequestForm robotomy("Bender");
        PresidentialPardonForm pardon("Marvin");
		
		std::cout << "==============Status============" << std::endl;
        std::cout << bureaucrat << std::endl;
        std::cout << shrubbery << std::endl;
        std::cout << robotomy << std::endl;
        std::cout << pardon << std::endl;
		std::cout << "==============Signed============" << std::endl;
        bureaucrat.signForm(shrubbery);
        bureaucrat.signForm(robotomy);
        bureaucrat.signForm(pardon);
		std::cout << "==============Execute============" << std::endl;
        bureaucrat.executeForm(shrubbery);
        bureaucrat.executeForm(robotomy);
        bureaucrat.executeForm(pardon);

		std::cout << "==============LowGradeBureaucrat============" << std::endl;
        Bureaucrat low_grade_bureaucrat("LowGradeBureaucrat", 150);
        low_grade_bureaucrat.signForm(shrubbery);
        low_grade_bureaucrat.executeForm(shrubbery);

        std::cout << "==============Not Signed Form============" << std::endl;
        Bureaucrat high_grade_bureaucrat("HighGradeBureaucrat", 1);
        RobotomyRequestForm robotomy2("Jack");
        high_grade_bureaucrat.executeForm(robotomy2);
		
		std::cout << "==============InvalidGradeBureaucrat============" << std::endl;
        Bureaucrat invalid_grade_bureaucrat("InvalidGradeBureaucrat", 151);
        invalid_grade_bureaucrat.signForm(shrubbery);
        invalid_grade_bureaucrat.executeForm(shrubbery);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

