/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:23:19 by koseki.yusu       #+#    #+#             */
/*   Updated: 2025/02/16 06:45:24 by koseki.yusu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <fstream> 


class ShrubberyCreationForm : public AForm {
    public:
        ShrubberyCreationForm(const std::string& target);
        virtual ~ShrubberyCreationForm();

        void execute(Bureaucrat const & executor) const;

    private:
        const std::string _target;
};
