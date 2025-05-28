/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:24:46 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/05/28 13:19:30 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	std::cout << "------------------------- FORM TEST ---------------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "------------------ ShrubberyCreationForm Test -----------------" << std::endl;

	try
	{
		Bureaucrat bureaucrat("Lucas", 138);
		ShrubberyCreationForm form("home");

		std::cout << bureaucrat << std::endl;
		std::cout << form;

		std::cout << "\nBureaucrat tries to execute but doesn't have a high enough grade" << std::endl;
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form); 

		std::cout << "\nBureaucrat increments grade and now has a high enough grade" << std::endl;
		bureaucrat.ingrementGrade();
		std::cout << bureaucrat << std::endl;
		bureaucrat.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "----------------- PresidentialPardonForm Test -----------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;

	try
	{
		Bureaucrat bureaucrat("Leila", 25);
		PresidentialPardonForm form("Billy");

		std::cout << bureaucrat << std::endl;
		std::cout << form;

		std::cout << "\nBureaucrat tries to execute but doesn't have a high enough grade" << std::endl;
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);

		std::cout << "\nBureaucrat increments grade and now has a high enough grade" << std::endl;
		for (int i = 0; i < 20; i++)
			bureaucrat.ingrementGrade();

		std::cout << bureaucrat << std::endl;
		bureaucrat.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "------------------ RobotomyRequestForm Test -------------------" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;

	try
	{
		Bureaucrat bureaucrat("Thais", 72);
		RobotomyRequestForm form("Form");

		std::cout << bureaucrat << std::endl;
		std::cout << form;

		std::cout << "\nBureaucrat tries to execute but doesn't have a high enough grade" << std::endl;
		bureaucrat.signForm(form);
		bureaucrat.executeForm(form);

		std::cout << "\nBureaucrat increments grade and now has a high enough grade" << std::endl;
		for (int i = 0; i < 27; i++)
			bureaucrat.ingrementGrade();

		std::cout << bureaucrat << std::endl;
		bureaucrat.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
