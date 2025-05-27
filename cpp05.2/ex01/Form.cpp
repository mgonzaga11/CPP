/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:45:26 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/05/27 18:56:54 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : Name("empty"), toSign(-1), toExec(-1), isSigned(false){
		if(toSign  > 150 || toExec > 150)
		throw GradeTooLowException();
	if(toSign < 1 || toExec < 1)
		throw GradeTooHighException();
}

Form::Form(const std::string Name, const int toSign, const int toExec_): 
Name(Name), toSign(toSign), toExec(toExec), isSigned(false){

	if(toSign > 150 || toExec > 150)
		throw GradeTooLowException();
	if(toSign < 1 || toExec < 1)
		throw GradeTooHighException();
}

Form::Form(const Form &other)
    : Name(other.Name),isSigned(other.isSigned),toSign(other.toSign),
      toExec(other.toExec) {}

std::string Form::GetName() const{
	return Name;	
}

int Form::GetToExec() const{
	return toExec;
}

int Form::GetToSign() const{
	return toSign;
}

bool    Form::getIsSigned() const {
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

    if (form.getIsSigned()) {
        out << form.GetName() << ", form is signed, requires grade " 
            << form.GetToSign() << " to sign, " << form.GetToExec()
            << " to execute.";
    }
    else {
        out << form.GetName() << ", form is unsigned, requires grade " 
            << form.GetToSign() << " to sign, " << form.GetToExec()
            << " to execute.";
    }
    return out;
}
