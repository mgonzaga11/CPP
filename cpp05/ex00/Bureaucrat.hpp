/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:00:53 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/05/13 14:50:10 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat{

	private:
		std::string const name;
		int grade;
	public:
		Bureaucrat(void);
		Bureaucrat(Bureaucrat const& that);
		Bureaucrat(std::string newName, int grade);
		~Bureaucrat(void);
		Bureaucrat &operator=(Bureaucrat const& that);
		std::string	getName(void) const;
		int			getGrade(void) const;
		void 		incrementGrade(void);
		void 		decrementGrade(void);
		class GradeTooHighException : public std::exception {
			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			const char* what() const throw();
		};

};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif