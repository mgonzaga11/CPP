/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:57:13 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/05/13 16:28:32 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
	
	private:
		std::string const Name;
		bool isSigned;
		int const			gradeToExecute;
		int const			gradeToSign;
	public:
		Form(void);
		Form(std::string name, int newGradeSign, int newGradeEx);
		Form(Form const &that);
		~Form(void);
		Form &operator=(Form const &src);
		const std::string &getName() const;
		bool get_sing() const;
		int getGradeToExecute() const;
		int getGradeToSign() const;
		void beSigned(const Bureaucrat& b);
		class GradeTooHighException : public std::exception {
			virtual const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception {
			virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, Form const &fr);

#endif