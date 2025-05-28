/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 14:47:56 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/05/28 11:45:55 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP


#include <string>
#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

class Bureaucrat;

class Form {
	private:
		const std::string Name;
		const int toSign;
		const int toExec;
		bool isSigned;
	public:
		Form(const std::string Name_, const int toSing_, const int toExec_);
		Form(const Form &other);
		Form& operator=(const Form &other);
		~Form();
		

		std::string GetName() const;
		int 		GetToSign() const;
		int			GetToExec() const;
		bool        getIsSign() const;
		class GradeTooHighException : public std::exception{
			virtual const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception{
			virtual const char* what() const throw();
		};
		void    beSigned(const Bureaucrat &other);

};
std::ostream &operator<<(std::ostream &out, const Form &form);

#endif