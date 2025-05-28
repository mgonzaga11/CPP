/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:39:48 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/05/28 14:03:38 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){}
	
Intern::Intern(const Intern &other){
	(void)other;
}
	
Intern& Intern::operator=(const Intern &other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}


static AForm *robotomyRequest(std::string target) {
  return new RobotomyRequestForm(target);
}

static AForm *shrubberyRequest(std::string target) {
  return new ShrubberyCreationForm(target);
}

static AForm *presidentialRequest(std::string target) {
  return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string formtype, std::string formTarget){
	
	std::string formNames[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};
	AForm	*(*f[3])(std::string formTarget) = {&robotomyRequest, &shrubberyRequest, &presidentialRequest};
	for (int i = 0; i < 4 ; i++) {
		if (!formNames[i].compare(formtype)) {
		std::cout << "Intern creates " << formNames[i] << std::endl;
		return (f[i](formTarget));
		}
	}
	throw FormNotFoundException();	
}

const char* Intern::FormNotFoundException::what() const throw()
{
	return "Intern cannot bring the form, doesn't exist";
}