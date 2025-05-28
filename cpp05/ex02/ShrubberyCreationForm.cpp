/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:54:48 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/05/27 19:07:18 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

	
	ShrubberyCreationForm::ShrubberyCreationForm(std::string target): 
		AForm("ShrubberyCreationForm", 145, 137), target(target){
		
	}
	
	ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) 
  	  : AForm(other), target(other.target) { }
	
	ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
		if(this != &other)
			this->target = other.target;	
		return *this;
	}

	ShrubberyCreationForm::~ShrubberyCreationForm(){}
	
	void ShrubberyCreationForm::action() const{
		
		std::string filename;
			
		filename = target + "_shrubbery";
		std::ofstream file(filename.c_str());
		if (file.is_open()) {
            file << "       *       \n";
			file << "      ***      \n";
			file << "     **o**     \n";
			file << "    *******    \n";
			file << "   **o***o**   \n";
			file << "  ***********  \n";
			file << " **o**o***o**o \n";
			file << "***************\n";
			file << "      |||      \n";
			file << "      |||      \n";
       		file.close();
		}
	}