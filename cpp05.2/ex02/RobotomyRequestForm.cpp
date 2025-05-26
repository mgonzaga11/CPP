/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:34:06 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/05/26 18:55:32 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm() 
    : AForm("RobotomyRequestForm", 72, 45), target("empty") {}
	
RobotomyRequestForm::RobotomyRequestForm(const std::string target)
	: AForm("RobotomyRequestForm", 72, 45), target(target) {}

	
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), target(other.target) {}
	
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    if (this != &other) {
            this->target = other.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){}


void RobotomyRequestForm::action() const{

	
}