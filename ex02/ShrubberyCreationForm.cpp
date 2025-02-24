/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:29:17 by koseki.yusu       #+#    #+#             */
/*   Updated: 2025/02/16 06:45:35 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("Shrubbery Creation", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
    if (!isSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw  AForm::GradeTooLowException();
    std::ofstream file((_target + "_shrubbery").c_str());
    if (file.is_open())
    {
        file << "        *         " << std::endl;
        file << "       ***        " << std::endl;
        file << "      *****       " << std::endl;
        file << "    *********     " << std::endl;
        file << "       | |        " << std::endl;
        file.close();
    }
}

