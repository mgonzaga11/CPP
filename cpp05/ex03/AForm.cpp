/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:45:26 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/05/28 13:48:42 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"


AForm::AForm(const std::string Name, const int toSign, const int toExec): 
Name(Name), toSign(toSign), toExec(toExec), isSigned(false){

	if(toSign > 150 || toExec > 150)
		throw GradeTooLowException();
	if(toSign < 1 || toExec < 1)
		throw GradeTooHighException();
}

AForm::AForm(const AForm &other)
    : Name(other.Name),toSign(other.toSign), toExec(other.toExec), isSigned(other.isSigned) {}
      
AForm::~AForm() {
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
    return "Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade too low!";       
}

std::ostream &operator<<(std::ostream &out, const AForm &form) {

    out << form.GetName() 
        << ", Form is " << (form.getIsSign() ? "signed" : "unsigned")
        << ", requires grade " << form.GetToSign() << " to sign, " 
        << form.GetToExec() << " to execute.\n";
    return out;
}

void    AForm::beSigned(const Bureaucrat &form) {
    
    if (form.getGrade() > this->GetToSign()) {
        throw AForm::GradeTooLowException();
    }
    this->isSigned = true;
}
