/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:24:46 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/05/28 14:19:23 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main(void)
{
	std::cout << "=============== INÍCIO DOS TESTES DE INTERN ===============" << std::endl;

	std::cout << "\n>>> Teste: Formulário ShrubberyCreation <<<" << std::endl;
	try
	{
		Bureaucrat bureaucrat("Ana", 120);
		std::cout << bureaucrat;
		Intern intern;
		AForm *form = intern.makeForm("shrubbery creation", "Parque Central");
		std::cout << *form;
		bureaucrat.signForm(*form);
		std::cout << *form;
		bureaucrat.executeForm(*form);
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << "Erro: " << e.what() << std::endl;
	}

	std::cout << "\n>>> Teste: Formulário PresidentialPardon <<<" << std::endl;
	try
	{
		Bureaucrat bureaucrat("Carlos", 1);
		std::cout << bureaucrat;
		Intern intern;
		AForm *form = intern.makeForm("presidential pardon", "Joana");
		std::cout << *form;
		bureaucrat.signForm(*form);
		std::cout << *form;
		bureaucrat.executeForm(*form);
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << "Erro: " << e.what() << std::endl;
	}

	std::cout << "\n>>> Teste: Formulário RobotomyRequest <<<" << std::endl;
	try
	{
		Bureaucrat bureaucrat("Bruno", 45);
		std::cout << bureaucrat;
		Intern intern;
		AForm *form = intern.makeForm("robotomyrequest", "Marvin");
		std::cout << *form;
		bureaucrat.signForm(*form);
		std::cout << *form;
		bureaucrat.executeForm(*form);
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << "Erro: " << e.what() << std::endl;
	}

	std::cout << "\n>>> Teste: Formulário Inexistente <<<" << std::endl;
	try
	{
		Intern intern;
		AForm *form = intern.makeForm("formulario desconhecido", "Nome");
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << "Erro: " << e.what() << std::endl;
	}

	std::cout << "\n=============== FIM DOS TESTES ===============" << std::endl;

	return 0;
}