/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:26:16 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/11/28 23:55:01 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void check_form(const std::string& name, int sign_g, int exec_g){
    try {
        Form form = Form(name, sign_g, exec_g);
        std::cout << form << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

int main()
{
    check_form("Form_OK", 1, 150);
	check_form("Form_NG", 1, 151);
	check_form("Form_NG", -1, 150);
	check_form("Form_NG", -2, 155);

    Bureaucrat	ber1 = Bureaucrat("employee", 100);
    Bureaucrat	ber2 = Bureaucrat("executive", 50);
	Bureaucrat	ber3 = Bureaucrat("President", 1);
    
    Form	form1 = Form("low_level", 144, 120);
	Form	form2 = Form("medium_level", 99, 80);
	Form	form3 = Form("topsecret_level", 2, 1);

    std::cout << std::endl << "Employee" << std::endl;
	ber1.signForm(form1);
	ber1.signForm(form2);
	ber1.signForm(form3);
	std::cout << "Executive" << std::endl;
	ber2.signForm(form1);
	ber2.signForm(form2);
	ber2.signForm(form3);
    std::cout << "President" << std::endl;
	ber3.signForm(form1);
	ber3.signForm(form2);
	ber3.signForm(form3);
}