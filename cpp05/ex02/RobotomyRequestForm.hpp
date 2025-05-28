/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:22:00 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/05/27 19:05:09 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm {
    
    private:
        std::string target;
            
    protected:
        void action() const;
    
    public:
        RobotomyRequestForm(const RobotomyRequestForm &other); 
        RobotomyRequestForm &operator=(const RobotomyRequestForm &other); 
        ~RobotomyRequestForm(); 
        RobotomyRequestForm(const std::string target); 
};

#endif
