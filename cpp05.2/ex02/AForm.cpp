/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:45:26 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/05/26 17:14:42 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : Name("empty"), toSign(-1), toExec(-1), isSigned(false){}

AForm::AForm(const std::string Name_, const int toSing_, const int toExec_): 
Name("empty"), toSign(toSing_), toExec(toExec_), isSigned(false){

	if(toSing_ > 150 || toExec_ > 150)
		throw GradeTooLowException();
	if(toSing_ < 1 || toExec_ < 1)
		throw GradeTooHighException();
}

std::string AForm::GetName() const{
	return Name;	
}

int AForm::GetToExec() const{
	return toExec;
}

int AForm::GetToSign() const{
	return toSign;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade too low!";
}


bool AForm::getIsSign() const
{
	return isSigned;
}

void AForm::execute( Bureaucrat const & executor) const
{
	if(getIsSign() == false)
		throw exceptionnotsign();
	if(executor.getGrade() > this->GetToExec())
		throw GradeTooLowException();
	this->action();
}

const char* AForm::exceptionnotsign:: what() const throw(){
	return "Form is not signed!";
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm: Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "AForm: Grade too low!";       
}

std::ostream &opertor<<