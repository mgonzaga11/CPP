/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 17:26:15 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/05/26 18:41:22 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : 
	AForm("PresidentialPardonForm", 25, 5), target("empty") {}
	
PresidentialPardonForm::PresidentialPardonForm(std::string target_)
	: target(target_), AForm("PresidentialPardonForm", 25, 5){}
	

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other), target(other.target) {}
	
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other){
	if(this != &other)
		this->target = other.target;	
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){}

void PresidentialPardonForm::action()const{
	std::cout << "Informs that" << target << "has been pardoned by Zaphod Beeblebrox.";
}
