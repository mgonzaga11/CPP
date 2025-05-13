/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:44:03 by mgonzaga          #+#    #+#             */
/*   Updated: 2025/05/13 14:44:07 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    std::cout << "----- Teste de criação válida -----" << std::endl;
    try {
        Bureaucrat a("Alice", 42);
        std::cout << a << std::endl;
    } catch (std::exception& e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    std::cout << "\n----- Teste de criação com grau muito alto (0) -----" << std::endl;
    try {
        Bureaucrat b("Bob", 0); // Deve lançar GradeTooHighException
    } catch (std::exception& e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    std::cout << "\n----- Teste de criação com grau muito baixo (151) -----" << std::endl;
    try {
        Bureaucrat c("Charlie", 151); // Deve lançar GradeTooLowException
    } catch (std::exception& e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }

    std::cout << "\n----- Teste de incremento (subir de 2 para 1 e falhar ao passar de 1) -----" << std::endl;
    try {
        Bureaucrat d("Diana", 2);
        std::cout << d << std::endl;

        d.incrementGrade(); // 2 -> 1
        std::cout << "Depois do incremento: " << d << std::endl;

        d.incrementGrade(); // 1 -> erro
    } catch (std::exception& e) {
        std::cout << "Erro ao incrementar: " << e.what() << std::endl;
    }

    std::cout << "\n----- Teste de decremento (descer de 149 para 150 e falhar ao passar de 150) -----" << std::endl;
    try {
        Bureaucrat e("Edu", 149);
        std::cout << e << std::endl;

        e.decrementGrade(); // 149 -> 150
        std::cout << "Depois do decremento: " << e << std::endl;

        e.decrementGrade(); // 150 -> erro
    } catch (std::exception& e) {
        std::cout << "Erro ao decrementar: " << e.what() << std::endl;
    }

    return 0;
}
