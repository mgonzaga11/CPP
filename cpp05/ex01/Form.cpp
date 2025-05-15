/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:57:06 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/05/15 19:23:08 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : Name("Unknown"), isSigned(false), gradeToExecute(100), gradeToSign(100){}

Form::Form(const std::string Name_, const int gradeToSign, const int gradeToExecute) : Name(Name_), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute){
	if(gradeToExecute < 1 || gradeToSign < 1)
		throw GradeTooHighException();
	if(gradeToExecute > 150 || gradeToSign > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other) : Name(other.Name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute){}

Form& Form::operator=(const Form &other){
	if (this != &other) {
		this->isSigned = other.isSigned;
	}
	return *this;
}


const char *Form::GradeTooHighException::what() const throw(){
	return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw(){
	return "Grade is too low!";
}

const std::string &Form::getName() const{
	return Name;
}

bool Form::get_sing() const{
	return isSigned;	
}

int Form::getGradeToExecute() const{
	return gradeToExecute;
}

int Form::getGradeToSign() const{
	return gradeToSign;
}

void Form::beSigned(const Bureaucrat& b){
	if(b.getGrade() > getGradeToSign())
		throw GradeTooLowException();
	else 
		isSigned = true; 
}

