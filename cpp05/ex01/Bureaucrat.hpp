/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:45:53 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/05/28 14:14:35 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP 

#include <string>
#include <exception>
#include <iostream>
#include <ostream>
#include "Form.hpp"

class Form;

class Bureaucrat{
	private:
		const std::string name;	
		int grade;
	public:
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();
		std::string getName() const;
		int getGrade() const;
		void ingrementGrade();
		void decrementGrade();
		void    signForm(Form &paper);
		class GradeTooHighException : public std::exception{
			virtual const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception{
			virtual const char* what() const throw();
		};
	};
	std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif