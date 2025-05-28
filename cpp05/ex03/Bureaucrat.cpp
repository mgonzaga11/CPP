/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:32:35 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/05/28 13:47:29 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat( const std::string _name, const int _grade): name(_name) , grade(_grade){
	if(_grade < 1)
		throw GradeTooHighException();
	else if(_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): name(other.getName()), grade(other.getGrade()){}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& other){
	if(this != &other)
	{
		this->grade = other.getGrade();
	}
	return(*this);
}

Bureaucrat::~Bureaucrat() {
}

std::string Bureaucrat::getName() const{
	return name;
}

int Bureaucrat::getGrade() const {
	return grade;
}

void Bureaucrat::ingrementGrade(){
	if(grade <= 1)
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::decrementGrade()
{
	if(grade >= 150)
		throw GradeTooLowException();
	grade++;
}
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low!";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &other) {

    out << other.getName() << ", bureaucrat grade " << other.getGrade() << ".\n";;
    return out;
}

void Bureaucrat::signForm(AForm &form) {
    try {
        form.beSigned(*this);
        std::cout << name << " successfully signed " << form.GetName() << "." << std::endl;
    } catch (const std::exception &e) {
        std::cerr << name << " couldn't sign " << form.GetName()
                  << " because: " << e.what() << "." << std::endl;
    }
}


void Bureaucrat::executeForm(const AForm &form) const {
    try {
        form.execute(*this);
        std::cout << name << " executed " << form.GetName() << "." << std::endl;
    } catch (const std::exception &e) {
        std::cerr << name << " couldn't execute " << form.GetName()
                  << " because: " << e.what() << "." << std::endl;
    }
}