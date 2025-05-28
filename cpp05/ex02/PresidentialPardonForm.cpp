/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 17:26:15 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/05/28 13:24:55 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

	
PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("PresidentialPardonForm", 25, 5), target(target) {}
	
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other), target(other.target) {}
	
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other){
	if(this != &other)
		this->target = other.target;	
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void){}

void PresidentialPardonForm::action()const{
	std::cout << "Informs that " << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
