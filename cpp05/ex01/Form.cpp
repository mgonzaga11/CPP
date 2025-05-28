/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:45:26 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/05/28 13:48:51 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string Name, const int toSign, const int toExec): 
Name(Name), toSign(toSign), toExec(toExec), isSigned(false){

	if(toSign > 150 || toExec > 150)
		throw GradeTooLowException();
	if(toSign < 1 || toExec < 1)
		throw GradeTooHighException();
}

Form::Form(const Form &other)
    : Name(other.Name),toSign(other.toSign),
      toExec(other.toExec), isSigned(other.isSigned) {}
      
Form::~Form(){}

std::string Form::GetName() const{
	return Name;	
}

int Form::GetToExec() const{
	return toExec;
}

int Form::GetToSign() const{
	return toSign;
}

bool    Form::getIsSign() const {
    return isSigned;
}


const char* Form::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade too low!";
}


void    Form::beSigned(const Bureaucrat &other) {

    if (other.getGrade() > this->GetToSign()) {
        throw Form::GradeTooLowException();
    }
    this->isSigned = true;
}


std::ostream &operator<<(std::ostream &out, const Form &form) {

    out << form.GetName() 
        << ", Form is " << (form.getIsSign() ? "signed" : "unsigned")
        << ", requires grade " << form.GetToSign() << " to sign, " 
        << form.GetToExec() << " to execute.\n";
    return out;
}
