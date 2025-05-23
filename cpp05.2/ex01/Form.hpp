/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 14:47:56 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/05/23 14:44:54 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>

class Form {
	private:
		const std::string Name;
		bool isSigned;
		const int toSign;
		const int toExec;
	public:
		Form();
		Form(const std::string Name_, const int toSing_, const int toExec_);
		Form(const Form &other);
		Form& operator=(const Form &other);
		~Form();
		

		std::string GetName() const;
		int GetToSign() const;
		int GetToExec() const;
		class GradeTooHighException : public std::exception{
			virtual const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception{
			virtual const char* what() const throw();
		};
};

#endif