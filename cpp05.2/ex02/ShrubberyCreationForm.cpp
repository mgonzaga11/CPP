/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:54:48 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/05/26 12:12:11 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"


	ShrubberyCreationForm::ShrubberyCreationForm(): 
	AForm("ShrubberyCreationForm", 145, 137), target("empty") {}
	
	ShrubberyCreationForm::ShrubberyCreationForm(std::string target): 
	AForm("ShrubberyCreationForm", 145, 137), target("target"){
		
	}
	
	ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& other){
		
	}
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

	virtual ~ShrubberyCreationForm();
	void execute(Bureaucrat const &executor) const;