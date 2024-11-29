/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koseki.yusuke <koseki.yusuke@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:23:19 by koseki.yusu       #+#    #+#             */
/*   Updated: 2024/11/29 11:37:43 by koseki.yusu      ###   ########.fr       */
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
        const std::string target_;
};
