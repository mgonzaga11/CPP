/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:24:46 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/05/28 14:16:50 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main() {

std::cout << std::endl;
	std::cout << "========================= BUREAUCRAT TEST  ===========================" << std::endl;
	std::cout << "=================================================================\n" << std::endl;

    std::cout << " Criando Bureaucrat com nota válida:" << std::endl;
    try {
        Bureaucrat b1("Alice", 75);
        std::cout << b1 << std::endl;

        std::cout << "\n Incrementando nota:" << std::endl;
        b1.incrementGrade();
        std::cout << b1 << std::endl;

        std::cout << "\n Decrementando nota:" << std::endl;
        b1.decrementGrade();
        std::cout << b1 << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    std::cout << "\n Criando Bureaucrat com nota muito alta (0):" << std::endl;
    try {
        Bureaucrat b2("Bob", 0); // Deve lançar exceção
    }
    catch (std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    std::cout << "\n Criando Bureaucrat com nota muito baixa (151):" << std::endl;
    try {
        Bureaucrat b3("Charlie", 151); // Deve lançar exceção
    }
    catch (std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    std::cout << "\n Testando limite superior (nota 1) com incremento:" << std::endl;
    try {
        Bureaucrat b4("Diana", 1);
        std::cout << b4 << std::endl;
        b4.incrementGrade(); // Deve lançar exceção
    }
    catch (std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    std::cout << "\n Testando limite inferior (nota 150) com decremento:" << std::endl;
    try {
        Bureaucrat b5("Eve", 150);
        std::cout << b5 << std::endl;
        b5.decrementGrade(); // Deve lançar exceção
    }
    catch (std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }

    return 0;
}