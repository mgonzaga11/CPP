/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 14:47:56 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/05/26 16:16:09 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include "Bureaucrat.hpp"
#include <exception>

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
		AForm(const std::string Name_, const int toSing_, const int toExec_);
		AForm(const AForm &other);
		AForm& operator=(const AForm &other);
		virtual ~AForm();
		
		void execute(Bureaucrat const & executor) const;
		std::string GetName() const;
		bool getIsSign() const;
		int GetToSign() const;
		int GetToExec() const;
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

#endif