/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:27:40 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/11/29 11:40:29 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <iostream>

class RobotomyRequestForm : public AForm {
    public:
        RobotomyRequestForm(const std::string& target);
        virtual ~RobotomyRequestForm();

        void execute(Bureaucrat const& executor) const;

    private:
        const std::string target_;
};