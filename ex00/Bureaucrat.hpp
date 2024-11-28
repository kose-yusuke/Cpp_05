/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:18:34 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/11/28 16:53:16 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat {
    private:
        const std::string _name;
        int grade;
    public:
        Bureaucrat(const std::string& name, int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);

        std::string& getName() const;
        int getGrade() const;

        void incrementGrade();
        void decrementGrade();
}