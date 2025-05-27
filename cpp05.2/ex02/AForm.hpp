/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 14:47:56 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/05/27 18:55:43 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

class Bureaucrat;

class AForm {
	private:
		const std::string Name;
		bool isSigned;
		const int toSign;
		const int toExec;
		
	protected:
		virtual void action()const = 0;
		
	public:
		AForm();
		AForm(const std::string Name, const int toSing, const int toExec);
		AForm(const AForm &other);
		AForm& operator=(const AForm &other);
		virtual ~AForm();
		
		std::string GetName() const;
		bool getIsSign() const;
		int GetToSign() const;
		int GetToExec() const;
		void    beSigned(const Bureaucrat &guy);
		void execute(Bureaucrat const & executor) const;
		
    
		class GradeTooHighException : public std::exception{
			virtual const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception{
			virtual const char* what() const throw();
		};
		
		class exceptionnotsign: public std::exception{
			virtual const char *what() const throw();
		};
		
	};
	std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif