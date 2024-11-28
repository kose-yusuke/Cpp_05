/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:26:16 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/11/28 19:25:27 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat bob("Bob", 2);
        std::cout << bob << std::endl;

        bob.incrementGrade();
        std::cout << bob << std::endl;
        
        // GradeTooHighException
        bob.incrementGrade();
    } catch (const std::exception& e) {
        std::cerr << "Exception :" << e.what() << std::endl;
    }

    try {
        Bureaucrat alice("Alice", 149);
        std::cout << alice << std::endl;

        alice.decrementGrade();
        std::cout << alice << std::endl;

        // GradeTooLowException
        alice.decrementGrade();
    } catch (const std::exception& e) {
        std::cerr << "Exception :" << e.what() << std::endl;
    }
}