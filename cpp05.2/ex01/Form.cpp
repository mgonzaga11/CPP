/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:45:26 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/05/23 17:24:08 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : Name("empty"), toSign(-1), toExec(-1), isSigned(false){}

Form::Form(const std::string Name_, const int toSing_, const int toExec_): 
Name("empty"), toSign(toSing_), toExec(toExec_), isSigned(false){

	if(toSing_ > 150 || toExec_ > 150)
		throw GradeTooLowException;
	if(toSing_ < 1 || toExec_ < 1)
		throw GradeTooHighException;
}

std::string Form::GetName() const{
	return Name;	
}

int Form::GetToExec() const{
	return toExec;
}

int Form::GetToSign() const{
	return toSign;
}

Form::GradeTooHighExceptiong: 
